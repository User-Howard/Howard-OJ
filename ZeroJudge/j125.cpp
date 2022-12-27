#include <iostream>
#include <string.h>
#include <queue>
using namespace std;



int N;
int puzzle[301][301];
int steps[301][301];
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
const int INF = 0x3f3f3f3f;

int tt = 0;
void clear() {

}
int bfs(int m) {
    fill(&steps[0][0], &steps[0][0] + sizeof(steps)/sizeof(steps[0][0]), INF);
    ++tt;
    queue<pair<int, int> > Q;
    Q.push(make_pair(0, 0));
    steps[0][0] = 0;
    while(!Q.empty()) {
        int x = Q.front().first, y = Q.front().second; Q.pop();
        for(int dis=0;dis<4;dis++) {
            int nx = x + dx[dis], ny = y + dy[dis];
            if(nx<0 or ny<0 or N<=nx or N<=ny) 
                continue;
            if(abs(puzzle[x][y] - puzzle[nx][ny]) > m) 
                continue;
            if(steps[x][y]+1 < steps[nx][ny]) {
                steps[nx][ny] = steps[x][y] + 1;
                Q.push(make_pair(nx, ny));
            }
        }
    }
    return steps[N-1][N-1];
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0;i<N;++i) {
        for(int j=0;j<N;++j) {
            cin >> puzzle[i][j];
        }
    }
    int l = -1, r = 1e6;
    while(r-l > 1) {
        int mid = (r+l)/2;
        if(bfs(mid) != INF) 
            r = mid;
        else 
            l = mid;
        
    }
    cout << r << '\n' << bfs(r) << '\n';
    return 0;
}