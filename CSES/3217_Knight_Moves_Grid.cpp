#include <functional>
#include <iostream>
#include <queue>
using namespace std;


const int maxn = 1e3 + 5;
const int inf = 1e9 + 7;
const int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int dp[maxn][maxn];
int N;
bool check(int x, int y) {
    return x>=0 and y>=0 and x<N and y<N;
}
void init() {
    fill(&dp[0][0], &dp[0][0]+maxn*maxn, inf);
}
int main() {
    init();
    cin >> N;
    using tiii = tuple<int, int, int>;
    priority_queue<tiii, vector<tiii>, greater<tiii> > pq;
    dp[0][0] = 0;
    pq.emplace(0, 0, 0);
    while(not pq.empty()) {
        auto [step, x, y] = pq.top(); pq.pop();
        if(dp[x][y] != step) continue;
        for(int d=0;d<8;++d) {
            int nx = x+dx[d];
            int ny = y+dy[d];
            if(not check(nx, ny)) continue;
            if(dp[nx][ny] <= step+1) continue;
            dp[nx][ny] = step+1;
            pq.emplace(step+1, nx, ny);
        }
    }
    for(int i=0;i<N;++i) {
        for(int j=0;j<N;++j) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
