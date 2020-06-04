Case=1
while True:
    try:
        n,m=[int(i) for i in input().split()]
    except EOFError:
        break
    if(n==0 or m==0):
        break
    r=1
    arr=[-1 for i in range(n)]
    for i in range(m):
        a,b=[int(i) for i in input().split()]
        if(arr[b-1]==-1):
            a,b=b,a

        if(arr[a-1]==-1 and arr[b-1]==-1):
            arr[a-1],arr[b-1]=r,r
            r+=1
        elif(arr[a-1]==-1 and arr[b-1]!=-1):
            arr[a-1]=arr[b-1]
        else:
            rest=arr[b-1]
            for i in range(len(arr)):
                if arr[i]==rest:
                    arr[i]=arr[a-1]
            r+=1
        


    visit=[0 for i in range(n)]
    S=0
    for i in arr:
        if(i == -1):
            S+=1
            continue
        if(visit[i-1] == 1):
            continue
        visit[i-1]=1;
        S+=1
    print("Case {}: {}".format(Case,S))
    Case+=1
