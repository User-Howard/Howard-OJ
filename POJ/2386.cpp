#include<iostream>
using namespace std;


const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int dy[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int N, M;
char arr[102][102];
void dfs(int x, int y){
    if(arr[x][y] == '.')
        return;
    arr[x][y] = '.';
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            int nx = x+dx[i], ny = y+dy[j];
            if(nx<0||ny<0||nx==N||ny==M)
                continue;
            else
                dfs(nx, ny);
        }
    }
}
int main(){
    scanf("%d%d", &N, &M);
    for(int i=0;i<N;i++)
        scanf("%s", arr[i]);
    int answer=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(arr[i][j]=='W'){
                answer++;
                dfs(i, j);
            }
        }
    }
    cout<<answer<<endl;
    return 0;
}
