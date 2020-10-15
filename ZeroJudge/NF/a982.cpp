#include<iostream>
#include<queue>

using namespace std;

int N;
char arr[102][102];
queue<pair<int, int>>que;

void bfs(int x, int y){
    if(x>0)
        que.push(make_pair(x-1, y));
    else if(y>0)
        que.push(make_pair(x, y-1));
    else if(x<N-1)
        que.push(make_pair(x+1, y));
    else if(y<N-1)
        que.push(make_pair(x, y+1));
}
int main(){
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%c", &arr[i][j]);
        }
    }

    for

    return 0;
}
