lint = [int(i) for i in input().split()]
if max(lint)%min(lint) == 0:
    print('Y')
else:
    print('N')