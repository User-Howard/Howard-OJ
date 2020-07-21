# NF
""" 
0 1 2
3 4 5
6 7 8
"""
AC = {'O':0, 'X':0, '-':0}
def judge(arr):
    for player in ['O', 'X']:
        if any([arr[i*3]==arr[i*3+1]==arr[i*3+2]==player or arr[i]==arr[i+3]==arr[i+6]==player for i in range(3)]):
            return player
        
        if arr[0]==arr[4]==arr[8]==player or arr[2]==arr[4]==arr[6]==player:
            return player

    return 0

def dfs(arr, pn):
    ans=[]
    idx = [i for i in range(9) if arr[i]=='-']
    if judge(arr):
        AC[judge(arr)]+=1
        return
    elif len(idx)==0:
        AC['-']+=1

    for i in idx:
        dfs((arr[:i]+pn+arr[i+1:]), 'O' if pn=='X' else 'X')


try:
    arr = input()
    dfs(arr, 'O')
    print(judge(arr))
except:
    print('Error!')