import os
import re
import sys
from enum import Enum

from typing import Optional

from pydantic_settings import BaseSettings, SettingsConfigDict
from pydantic import Field, field_validator, model_validator, BaseModel
from pathlib import Path

BASE_DIR = Path(__file__).parent.parent.parent

class Settings(BaseSettings):
    issue_number: str = Field(default=...)
    issue_body: str = Field(default=...)
    repo_full_name: str = Field(default=...)
    gh_token: str = Field(default=..., validation_alias="GITHUB_TOKEN")
    anthropic_key: str = Field(default=..., validation_alias="ANTHROPIC_API_KEY")
    github_output: Optional[str] = Field(default=None)

    agent_model: str = Field(default="gateway/openai:gpt-4o-mini")

    model_config = SettingsConfigDict(
        env_file=".env",
        env_file_encoding="utf-8"
    )
    @field_validator("issue_body")
    def fix_newlines(cls, v):
        return v.replace("\\n", "\n")

class Language(str, Enum):
    CPP = "C++"
    PYTHON = "Python"
    RUST = "Rust"
    C = "C"
    SWIFT = "Swift"

    @property
    def extension(self) -> str:
        return {
            Language.CPP: ".cpp",
            Language.PYTHON: ".py",
            Language.RUST: ".rs",
            Language.C: ".c",
            Language.SWIFT: ".swift",
        }[self]

class Platform(str, Enum):
    LEETCODE = "LeetCode"
    CODEFORCES = "CodeForces"
    CSES = "CSES"
    KATTIS = "Kattis"
    APCS = "APCS"
    NPSC = "NPSC"
    POJ = "POJ"
    TIOJ = "TIOJ"
    SEOJ = "SEOJ"
    UVA = "UVA"
    VJUDGE = "VJudge"
    ZEROJUDGE = "ZeroJudge"

    @property
    def directory(self) -> str:
        return self.value


class Difficulty(str, Enum):
    EASY = "Easy"
    MEDIUM = "Medium"
    HARD = "Hard"
    UNKNOWN = "Unknown"


class IssueData(BaseModel):
    platform: Platform
    problem_id: str
    problem_title: str
    difficulty: Difficulty
    language: Language
    commit_message: str
    solution_code: str

    @model_validator(mode="before")
    def parse_issue(cls, values: str):
        sections = dict(
            re.findall(r"###\s*(.*?)\n+(.*?)(?=\n###|\Z)", values, re.DOTALL)
        )

        platform = sections.get("Platform")
        problem_id = sections.get("Problem ID")
        problem_title = sections.get("Problem Title")
        difficulty = sections.get("Difficulty")
        language = sections.get("Language")
        commit_message = sections.get("Commit Message", "")
        solution_code = sections.get("Solution Code")

        if not platform:
            raise ValueError("Missing 'Platform' in issue body")
        if not problem_id or '#' in problem_id:
            raise ValueError("Missing 'Problem ID' in issue body")
        if not language:
            raise ValueError("Missing 'Language' in issue body")
        if solution_code is None:
            raise ValueError("Missing 'Solution Code' in issue body")

        return {
            "platform": platform.strip(),
            "problem_id": problem_id.strip(),
            "problem_title": (problem_title or "").strip(),
            "difficulty": (difficulty or "Unknown").strip(),
            "language": language.strip(),
            "commit_message": (commit_message or "").strip(),
            "solution_code": solution_code.strip(),
        }

    def file_name(self) -> str:
        ext = self.language.extension
        match self.platform:
            case Platform.LEETCODE:
                if self.problem_title:
                    title = self.problem_title.replace(" ", "_")
                    return f"{self.problem_id}_{title}{ext}"
                return f"{self.problem_id}{ext}"
            case Platform.CSES:
                return f"{self.problem_id}{ext}"
            case Platform.APCS:
                return f"{self.problem_id}{ext}"
            case _:
                return f"{self.problem_id}{ext}"


settings = Settings()

data = IssueData.model_validate(settings.issue_body)


platform_dir = BASE_DIR / data.platform.directory
file_path = platform_dir / data.file_name()

if file_path.exists():
    raise FileExistsError(f"Solution already exists: {file_path}")


# ── TODO: AI analysis (pydantic-ai) ────────────────────────────────────────
# tags, tc, sc = analyze(code)


# ── Write file ────────────────────────────────────────────────────────────
file_path.write_text(data.solution_code + "\n")

# ── Output ─────────────────────────────────────────────────────────────────
msg = data.commit_message or f"{data.difficulty.value.lower()}({data.platform.value}): {data.problem_id} {data.problem_title}"
if settings.github_output:
    with open(settings.github_output, "a") as f:
        f.write(f"commit_message={msg}\n")

sys.exit(0)  # 0 = success → issue will be closed
             # 1 = failure → issue stays open, error comment posted
