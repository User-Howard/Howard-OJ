while True:
    try:
        arr=input().split()
    except EOFError:
        break
    N=int(input())
    print(arr[-N])