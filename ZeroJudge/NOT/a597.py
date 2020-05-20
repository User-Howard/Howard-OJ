# include<iostream>
# using namespace std;


# int X,Y;
xr,yr = 0,0
arr = list()
count = 0
# bool de(int x, int y){
def de(x,y):
    global count, xr, yr
#     if(arr[x][y] == 'X')
    if(arr[xr][yr] == 'X'):
#         return 0;
        return 0;
#     else{
    else:
        count += 1
        arr[xr][xy] = 'X'
        
#     }
# }

# void solve() {
def solve():
    global count, xr, yr
    count=0
#     cin>>X>>Y;
    xr,yr=[int(i) for i in input().split()]
#     char arr[X][Y];
#     for(int x=0;x<X;x++)
    arr = [[] for i in range(xr)]
    for i in range(xr):
        arr[i].append(input())
    print(arr)
    for x in range(xr):
        for y in range(yr):
            if(arr[x][y] != 'X'):
                print("x={},y={}".format(x,y))
                de(x,y)
    print(count)

# }


# int main(void){
def main():
    global arr
#     ios::sync_with_stdio(false);
#     cin.tie(NULL);

#     for(int i=0;i<500;i++){

    for _ in range(1):
        arr.clear()
        solve();
#     }
#     return 0;
# }
main()