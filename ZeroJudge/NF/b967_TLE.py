
def dfs(n, visited, step=0):
    ext = {i for i, s in enumerate(state) if(n in s)} - set(visited)
    # print('\t'*step + f"->STEP[{step}] {n}\t{visited}")
    maxstep = step
    for i in ext:
        maxstep = max(maxstep, dfs(i, visited+[i], step+1))
    return maxstep

while True:
    try:
        N = int(input())
        state = [[] for i in range(N)]
        for _ in range(N-1):
            (p, q)= (int(i) for i in input().split())
            state[p].append(q)
            state[q].append(p)
    except EOFError:
        break
    print(max([dfs(i, [i]) for i in range(N)]))