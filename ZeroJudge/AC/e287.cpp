#include<iostream>
#include<vector>
using namespace std;


int N, M;
const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, -1, 1, 0};
const int INF = 0x3f3f3f3f;
int arr[102][102];
int road[102][102];
int dfs(int x, int y){
    int min_sum=INF, min_way;
    for (int i=0;i<4;i++) {
        int nx = x+dx[i], ny = y+dy[i];
        if (nx<0||ny<0||nx>=N||ny>=M||road[nx][ny])
            continue;
        if (arr[nx][ny]<min_sum) {
        	min_sum = arr[nx][ny];
        	min_way = i;
		}
    }
    int answer=0;
    if (min_sum==INF) {
        answer=0;
    } else {
        road[x][y] = true;
        answer = dfs(x+dx[min_way], y+dy[min_way]) + arr[x+dx[min_way]][y+dy[min_way]];
    }
    return answer;
}
int main(){
    cin>>N>>M;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cin>>arr[i][j];
        }
    }
    int min_sum=INF, min_x, min_y;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(arr[i][j]<min_sum){
                min_sum = arr[i][j];
                min_x = i;
                min_y = j;
            }
        }
    }
    cout<<dfs(min_x, min_y)+arr[min_x][min_y]<<endl;
    return 0;
}
