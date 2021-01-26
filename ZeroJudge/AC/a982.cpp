#include<iostream>
#include<string.h>
#include<queue>

using namespace std;

int N;
int arr[102][102]={0};
string board[102];
const int d4x[4] = {-1, 0, 0, 1};
const int d4y[4] = {0, -1, 1, 0};
const int INF = 0x3f3f3f3f;

bool is_available(int x, int y){
    return (x>=0)&&(y>=0)&&(x<N)&&(y<N)&&(board[x][y]=='.');
}
void dfs(int x, int y, int walk){
    if (arr[x][y]<=walk || !is_available(x, y))
        return;
    
    arr[x][y] = walk;
    for (int i=0;i<4;i++){
        int nx=x+d4x[i], ny=y+d4y[i];
        dfs(nx, ny, walk+1);
    }
    return;
}
int main(){
    scanf("%d", &N);
    for(int i=0;i<N;i++)
        cin>>board[i];
    
    memset(begin(arr), INF, sizeof(arr));
    dfs(1, 1, 1);
    if(arr[N-2][N-2]==INF)
        cout<<"No solution!"<<endl;
    else
        cout<<arr[N-2][N-2]<<endl;
    return 0;
}
