import sys
from functools import lru_cache

T = int(sys.stdin.readline().strip())
def solve():
    tmp = list(map(int, sys.stdin.readline().strip().split()))
    A = [(tmp[2*i], tmp[2*i+1]) for i in range(len(tmp)//2-1)]
    C = tmp[-2]
    D = tmp[-1]
    @lru_cache(None)
    def f(x, y):
        if x<=0 or y<=0:
            return D
        return sum(f(x-a, y-b) for a, b in A) + C

    queries = list(map(int, sys.stdin.readline().strip().split()))
    for i in range(len(queries)//2):
        x = queries[2*i]
        y = queries[2*i+1]
        print(f(x, y))
    print()

for _ in range(T):
    solve()