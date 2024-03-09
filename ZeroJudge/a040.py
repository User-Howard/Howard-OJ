def F(x: int, p: int):
    return sum([int(i)**p for i in str(x)])
A, B = map(int, input().split())
ans = [i for i in range(A, B+1)if F(i, len(str(i))) == i]
if ans:
    print(*ans)
else:
    print("none")
