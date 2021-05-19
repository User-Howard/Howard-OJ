while True:
    try:
        R=input()
    except EOFError:
        break
    for i in range(0,len(R)-1):
        print(str(ord(R[i])),end='_')
    print(ord(R[len(R)-1]))
        