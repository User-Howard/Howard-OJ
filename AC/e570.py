while 1:
    try:
        a = input()
    except EOFError:
        break

    if(a.find('之') != -1):
        b, c = a.split('之')
    elif(a.find('是') != -1):
        b, c = a.split('是')
    print(c+b)
