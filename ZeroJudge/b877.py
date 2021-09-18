a, b = map(int, input().split())
if a > b:
    print((100 + b) - a)
else:
    print(b - a)