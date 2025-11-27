from math import floor, log10

A = []
B = []
a = 1
b = 0
for i in range(1000000+1):
    a *= 1-1/(i+1)/(i+2)

    b += log10(i+1)
    b += log10(i+2)
    A.append(a)
    B.append(b)
while True:
    try:
        N = int(input())-1
    except EOFError:
        break
    a = A[N]
    b = B[N]
    print(f"{1-a:.6f} {floor(b)}")
