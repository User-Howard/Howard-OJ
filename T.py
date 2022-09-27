S = [list(map(int, i)) for i in input().split(',')]
N = len(S)
M = len(S[0])

answer = 0
maxX = [[0]*M]*N
maxY = [[0]*M]*N
dp = [[0]*M]*N

for i in range(N):
    for j in range(M):
        print(S[i][j], end=' ')
        if S[i][j] != 0:
            # maxX[i][j] = maxX[i][j-1] + 1
            maxX[i][j] = 9
        else:
            maxX[i][j] = 0
    print()
# for i in range(M):
#     maxY[0][i] = int(S[0][i] != 0)
#     for j in range(1, N):
#         if S[j][i] != 0:
#             maxY[j][i] = maxY[j-1][i] + 1
#         else:
#             maxY[j][i] = 0
print(S)
print(maxX)
# print(maxY)

print(dp)
for i in range(N):
    for j in range(M):
        pass
