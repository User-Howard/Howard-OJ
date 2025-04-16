l = sorted(list(map(lambda x: round(100*float(x)), input().split())))
# print(l)
target = round(float(input())*100)
mi = sum(l[:-1])
mx = sum(l[1:])
def solve():
    if 3*target < mi:
        return -1
    if mx<=3*target:
        return float('inf')
    return 3*target-sum(l[1:-1])

result = solve()
if result==-1:
    print("impossible")
elif result==float('inf'):
    print("infinite")
else:
    print(f"{result/100:.2f}")