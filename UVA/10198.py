dp = [0] * 1010
dp[5] = 1
for i in range(6, 1010):
    dp[i] += dp[i-1]*2 + dp[i-2] + dp[i-3]
while True:
    N = 0
    try:
        N = int(input())
    except EOFError:
        break
    print(dp[N+5])