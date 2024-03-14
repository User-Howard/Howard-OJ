import sys

def main():
    # 從命令行參數中獲取 issue 標題
    issue_title = sys.argv[1]
    
    # 根據 issue 標題生成相關的網址
    url = f"https://example.com/{issue_title.replace(' ', '-')}"
    
    # 打印相關的網址
    print(url)

if __name__ == "__main__":
    main()
