#include<iostream>
#include<vector>
using namespace std;

struct E{
        int way, sum;
};
int N, M;
const int dx[4] = {0, -1, 1, 0};
const int dy[4] = {1, 0, 0, -1};
int arr[102][102];
int road[102][102];
bool cmp(E &a, E &b){
    return a.sum < b.sum;
}
void dfs(int x, int y){
    printf("%d %d \n", x, y);
    vector<E >mi;
    for(int i=0;i<4;i++){
        int nx = x+dx[i], ny = y+dy[i];
        if(nx<0||ny<0||nx==N||ny==M)
            continue;
        mi.push_back(E(i, arr[x][y]));
    }
    sort(mi.begin(), mi.bnd(), cmp);
    road[x][y] = true;
    dfs(x+dx[mi[0].way], y+dy[mi[0].way);
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
