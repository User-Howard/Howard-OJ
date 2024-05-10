#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
using namespace std;


struct Cmp {
    bool operator()(const std::pair<int, int64_t>& a, const std::pair<int, int64_t>& b) const {
        return a.second > b.second;
    }
};
const int MAX_N = 1e5 + 10;
const int64_t INF = 2e14 + 10;
vector<pair<int, int64_t> > G[MAX_N];
int64_t dp[MAX_N] = {};
int main() {
    int N, M;
    cin >> N >> M;
    for(int i=0;i<M;++i) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back(make_pair(b, c));
    }
    fill(dp+2, dp+N+1, INF);
    priority_queue<pair<int, int64_t>, vector<pair<int, int64_t> >, Cmp> q;
    q.push(make_pair(1, 0LL));
    while(not q.empty()) {
        pair<int, int64_t> tmp = q.top(); q.pop();
    if(dp[tmp.first] < tmp.second) continue;
        for(auto i: G[tmp.first]) {
            if(tmp.second+i.second >= dp[i.first]) continue;
            dp[i.first] = tmp.second + i.second;
            q.push(make_pair(i.first, tmp.second + i.second));
        }
    }
    for(int i=1;i<=N;++i)
        cout << dp[i] << " \n"[i==N];

    return 0;
}
