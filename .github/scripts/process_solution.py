import os
import re
import sys


# ── Input ──────────────────────────────────────────────────────────────────
issue_number   = os.environ["ISSUE_NUMBER"]
issue_body     = os.environ["ISSUE_BODY"]
repo_full_name = os.environ["REPO_FULL_NAME"]
gh_token       = os.environ["GITHUB_TOKEN"]
anthropic_key  = os.environ["ANTHROPIC_API_KEY"]


# ── Parse issue body ────────────────────────────────────────────────────────
def extract(body: str, label: str) -> str:
    m = re.search(rf"### {label}\s*\n(.+?)(?=\n###|\Z)", body, re.DOTALL)
    return m.group(1).strip() if m else ""

platform   = extract(issue_body, "Platform")
problem_id = extract(issue_body, "Problem ID")
code       = extract(issue_body, "Solution Code")

print(f"platform:   {platform}")
print(f"problem_id: {problem_id}")
print(f"code lines: {len(code.splitlines())}")


# ── TODO: AI analysis (pydantic-ai) ────────────────────────────────────────
# tags, tc, sc = analyze(code)


# ── TODO: Write file + git commit ──────────────────────────────────────────
# file_path = resolve_path(platform, problem_id)
# write and commit...

print('-'*15)
print(issue_number)
print(issue_body)
print('-'*15)

# ── Output ─────────────────────────────────────────────────────────────────
sys.exit(0)  # 0 = success → issue will be closed
             # 1 = failure → issue stays open, error comment posted
