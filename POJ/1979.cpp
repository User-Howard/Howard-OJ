#include<iostream>
#include<string>
using namespace std;


int N, M, cnt=0;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
string table[22];
void dfs(int x, int y){
    cnt++;
    for(int i=0;i<4;i++){
        int nx = x+dx[i], ny = y+dy[i];
        if(nx>=0 && ny>=0 && nx<N && ny<M){
            if(table[nx][ny]=='.'){
                table[nx][ny] = '#';
                dfs(nx, ny);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> M >> N && N!=0 && M!=0){
        cnt=0;
        for(int i=0;i<N;i++)
            cin >> table[i];

        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                if(table[i][j]=='@')
                    dfs(i, j);
        cout << cnt << '\n';

    }
	return 0;
}
// finish time: 14	min, 48	sec, 25	hsec
