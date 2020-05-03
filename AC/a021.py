while 1:
    try:
        a = input()
    except EOFError:
        break
    
    Ans = eval(a.replace("/","//"))
    print(int(Ans))
