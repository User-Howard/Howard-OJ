n, m = map(int, input().split())

a1 = n * (n + 1) // 2 % n
print(a1**m % n)
