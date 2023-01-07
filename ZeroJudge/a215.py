from math import sqrt, floor
while True:
    try:
        N, M = map(int, input().split())
    except EOFError:
        break
    cnt = 0
    while (2*N + cnt)*(cnt+1) // 2 <= M:
        cnt += 1
    print(cnt+1)
         