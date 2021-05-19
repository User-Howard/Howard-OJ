a,b=[int(i) for i in input().split()]
if(a>b):
    a,b=b,a
S=0
for i in range(a,b+1):
    if(i%2==0):
        S+=i
print(S)