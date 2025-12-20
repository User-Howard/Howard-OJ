#include <functional>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define int int64_t


using pii = pair<int, int>;
using vpii = vector<pair<int, int> >;
const int MAX_N = 1e5 + 10;
const int INF = 2e14 + 10;
vpii G[MAX_N];
int dp[MAX_N] = {};
signed main() {
    int N, M;
    cin >> N >> M;
    for(int i=0;i<M;++i) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].emplace_back(b, c);
    }
    fill(dp, dp+MAX_N, INF);
    dp[1] = 0;
    priority_queue<pii, vpii, greater<pii>> pq;
    pq.push({0, 1});
    while(not pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(dp[u]!=d) continue;
        for(auto e: G[u]) {
            if(dp[e.first]>dp[u]+e.second) {
                dp[e.first] = dp[u]+e.second;
                pq.push({dp[e.first], e.first});
            }
        }
    }
    for(int i=1;i<=N;++i)
        cout << dp[i] << " \n"[i==N];

    return 0;
}
