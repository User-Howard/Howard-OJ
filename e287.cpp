#include<iostream>
#include<vector>
using namespace std;


int N, M;
const int dx[4] = {0, -1, 1, 0};
const int dy[4] = {1, 0, 0, -1};
int arr[102][102];
int road[102][102];
void dfs(int x, int y){
    printf("%d %d \n", x, y);
    int min_sum=-1, min_way;
    for(int i=0;i<4;i++){
        int nx = x+dx[i], ny = y+dy[i];
        if(nx<0||ny<0||nx==N||ny==M)
            continue;
        if(arr[nx][ny]<min_sum){
        	min_sum = arr[nx][ny];
        	min_way = i;
		}
    }
    road[x][y] = true;
    dfs(x+dx[min_way], y+dy[min_way]);
}
int main(){
    int N;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>arr[i][j];
        }
    }
    dfs(0, 0);
    return 0;
}
