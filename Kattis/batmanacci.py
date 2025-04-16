N, K = map(int, input().split())
li = [-1, 1, 1]
while li[-3] < K:
    li.append(li[-1] + li[-2])


def solve(n: int, k: int) -> str:
    if n == 1:
        return "N"
    if n == 2:
        return "A"
    if k <= li[n - 2]:
        return solve(n - 2, k)
    else:
        return solve(n - 1, k - li[n - 2])


print(solve(min(N, len(li) - 1), K))