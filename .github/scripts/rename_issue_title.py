import requests
import re
from bs4 import BeautifulSoup
import os

# 函数用于获取指定问题编号的标题
def get_problem_title(problem_id):
    url = f"https://cses.fi/problemset/task/{problem_id}/"
    response = requests.get(url)
    if response.status_code == 200:
        soup = BeautifulSoup(response.content, 'html.parser')
        title_element = soup.find('h1')
        if title_element:
            return title_element.text.strip()
    return None

# 用于修改问题标题的函数
def modify_issue_title(repo_name, issue_number, new_title):
    token = os.environ['GITHUB_TOKEN']
    headers = {
        'Authorization': f'token {token}',
        'Accept': 'application/vnd.github.v3+json'
    }
    url = f'https://api.github.com/repos/{repo_name}/issues/{issue_number}'
    data = {'title': new_title}
    response = requests.patch(url, headers=headers, json=data)
    if response.status_code == 200:
        return True
    return False

# 解析问题编号的函数
def extract_problem_id_from_title(issue_title):
    match = re.search(r'\[CSES\]\s*(\d+)', issue_title)
    if match:
        return match.group(1)
    return None

# 示例问题标题
issue_title = os.environ['INPUT_ISSUE_TITLE']
issue_number = os.environ['INPUT_ISSUE_NUMBER']
repo_name = os.environ['GITHUB_REPOSITORY']
problem_id = extract_problem_id_from_title(issue_title)

# 获取问题标题
new_title = None
if problem_id:
    problem_title = get_problem_title(problem_id)
    if problem_title:
        new_title = f"{issue_title}_{problem_title.replace(' ', '_')}"
print("title:", issue_title)
# 修改问题标题
if new_title:
    success = modify_issue_title(repo_name, issue_number, new_title)
    if success:
        print(f"问题标题已成功修改为：{new_title}")
    else:
        print("无法修改问题标题。")
else:
    print("无法获取问题标题或修改失败。")
