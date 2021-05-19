def solve():
    string = input()
    answer = 0
    for i in range(len(string)):
        if i+2<len(string) and string[i:i+3] == "RED":
            answer+=1
        if i+4<len(string) and string[i:i+5] == "GREEN":
            answer+=1
    print(f"1/{2**answer}")
        
while True:
    try:
        solve()
    except EOFError:
        break;