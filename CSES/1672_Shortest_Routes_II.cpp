#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
#define int int64_t
#define rep(x,a,b) for(int x=a;x<=b;x++)

const int INF = 1e18;
signed main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    int dp[505][505];
    fill(&dp[0][0], &dp[0][0] + 505*505, INF);
    while(M--) {
        int u, v, d;
        cin >> u >> v >> d;
        dp[u][v] = dp[v][u] = min(dp[u][v], d);
    }
    rep(i, 1, N) {
        dp[i][i] = 0;
    }
    rep(k, 1, N) {
        rep(i, 1, N) {
            rep(j, 1, N) {
                dp[i][j] = min(dp[i][k]+dp[k][j], dp[i][j]);
            }
        }
    }
    while(Q--) {
        int a, b;
        cin >> a >> b;
        cout << (dp[a][b]==INF ? -1 : dp[a][b]) << '\n';
    }
    return 0;
}