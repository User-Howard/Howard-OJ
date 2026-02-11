import sys
from collections import Counter
from dataclasses import dataclass
from datetime import datetime
from pathlib import Path
from typing import Iterable, Self

BASE_DIR = Path(__file__).parent.parent.parent
MAX_DEPTH = 2
EXCLUDE = {".git", ".github", ".zed", "tree", "文獻", "設計模式學習", "NOT FINISH"}

@dataclass(frozen=True)
class OnlineJudgeFolder:
    name: str
    count: int
    sub_folders: list[Self]
    suffixs: Counter[str]


    def _lines(self, depth: int = 0, prefix: str = "") -> Iterable[str]:
        yield f"{prefix}{self.name} -> {self.count}"
        for sub in self.sub_folders:
            if sub.count==0 or depth >= MAX_DEPTH:
                continue
            yield from sub._lines(depth + 1, prefix + " "*2)

    def __str__(self) -> str:
        return "\n".join(self._lines())

def is_submission(file: Path) -> bool:
    ext = [".c", ".cpp", ".py", ".rs", ".swift"]
    return file.suffix.lower() in ext

def enumerate_folder(current_folder: Path) -> OnlineJudgeFolder:
    subfolders = [item for item in current_folder.iterdir() if item.is_dir() and item.name not in EXCLUDE]
    files = [item for item in current_folder.iterdir() if not item.is_dir()]

    subfolder_stats = [enumerate_folder(folder) for folder in subfolders]

    subfolder_count = sum(folder.count for folder in subfolder_stats)
    current_count = sum(1 for file in files if is_submission(file))

    current_suffixs = Counter[str](suffix.suffix.lower() for suffix in files)
    subfolder_suffixs = sum([subfolder.suffixs for subfolder in subfolder_stats], Counter[str]())

    return OnlineJudgeFolder(
        name=current_folder.name,
        count=current_count+subfolder_count,
        sub_folders=subfolder_stats,
        suffixs=current_suffixs+subfolder_suffixs
    )

base = enumerate_folder(BASE_DIR)


readmeContent = f"""
# Howard-OJ

###### 專門紀錄我的程式資料夾。

`總共完成了 {base.count} 個題目。`

```
{base}
```
`最近更新日期：{datetime.now().strftime("%A, %B %d, %Y")}`

"""
print(readmeContent)
if "--write" in sys.argv:
    (BASE_DIR / "README.md").write_text(readmeContent)
