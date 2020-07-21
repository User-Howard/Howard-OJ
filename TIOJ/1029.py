# NF
def dfs(ilst, player=(0, 0), now=1):
    if now%2:
        pass
    
    return max(dfs(ilst[0:]))

input()
dfs([int(i) for i in input().split()])