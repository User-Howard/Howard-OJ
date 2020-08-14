N = int(input())
INF = [[int(toint) for toint in input().split()] for i in range(N-1)]

def eraseOnList(l, i):
    l.remove(i)
    return l

def road(x, se):
    for i in (0, 1):
        if se[i] == x:
            return se[1-i]
    return ;

def dfs(x, state, step=0):
    ext = [i for i in state if(x in i)]
    # print(f"Call({x}) -> ext={ext}")
    maxstep = step
    for i in ext:
        # print('\t'*step, road(x, i), state, step+1)
        maxstep = max(maxstep, dfs(road(x, i), eraseOnList(state, i), step+1))
    return maxstep


print(max([dfs(i, INF) for i in range(N)]))