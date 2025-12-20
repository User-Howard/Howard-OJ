#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define int int64_t

using tiii = tuple<int, int, int>;


const int inf = 1e18;
const int maxn = 2e5 + 5;
signed main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int> > adj[maxn];
    for(int i=0;i<M;++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }

    int dp[maxn][2];
    fill(&dp[0][0], &dp[0][0]+maxn*2, inf);
    dp[1][0] = 0;

    priority_queue<tiii, vector<tiii>, greater<tiii> > pq;
    pq.push({0, 1, 0});
    while(not pq.empty()) {
        auto [d, u, r] = pq.top(); pq.pop();
        if(dp[u][r] != d) continue;

        for(auto [v, c]: adj[u]) {
            bool flag = false;
            if(dp[v][0]>dp[u][0]+c) {
                dp[v][0] = dp[u][0]+c;
                flag = true;
            }
            if(dp[v][1]>dp[u][1]+c) {
                dp[v][1] = dp[u][1]+c;
                flag = true;
            }
            if(dp[v][1]>dp[u][0]+c) {
                dp[v][1] = dp[u][0]+c;
                flag = true;
            }
            if(dp[v][1]>dp[u][0]+c/2) {
                dp[v][1] = dp[u][0]+c/2;
                flag = true;
            }
            if(flag) {
                // i am too lazy to optimize this script
                pq.push({dp[v][0], v, 0});
                pq.push({dp[v][1], v, 1});
            }
        }
    }

    cout << min(dp[N][0], dp[N][1]) << '\n';

    return 0;
}
