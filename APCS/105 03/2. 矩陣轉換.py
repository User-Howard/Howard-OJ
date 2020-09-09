def solve(R, C, M):
    arr = []
    for i in range(R):
        arr.append(input().split())
    

while True:
    try:
        R, C, M = [int(i) for i in input().split()]
    except EOFError:
        break
    solve(R, C, M)