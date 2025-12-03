#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define int int64_t


const int maxn = 5e2 + 5;
const int INF = 1e9;
int N, M;
int S, T;
struct Edge {
    int v, flow;
    int r_id;
};
vector<Edge> E[maxn];
int level[maxn];
bool bfs() {
    for(int i=0;i<N;++i) {
        level[i+1] = -1;
    }
    level[S] = 0;
    queue<int> que;
    que.push(S);
    while(not que.empty()) {
        int u = que.front(); que.pop();
        for(auto e: E[u]) {
            if(e.flow<=0) continue;
            if(level[e.v] != -1) continue;

            level[e.v] = level[u] + 1;
            que.push(e.v);
        }
    }
    return level[T] != -1;
}
int dfs(int u, int cap) {
    if(u == T) return cap;
    // cerr << u << ' ' << cap << '\n';
    int sm = 0;
    for(auto& e: E[u]) {
        if(e.flow<=0) continue;
        if(level[e.v]!=level[u]+1) continue;

        int max_cap = min(e.flow, cap);
        int result = dfs(e.v, max_cap);
        sm += result;
        cap -= result;
        e.flow -= result;
        E[e.v][e.r_id].flow += result;
    }
    if(sm == 0)
        level[u] = -1;
    return sm;
}
signed main() {
    // freopen("in", "r", stdin);
    cin >> N >> M;
    S = 1, T = N;
    for(int i=0;i<M;++i) {
        int u, v, f;
        cin >> u >> v >> f;
        int uid = E[u].size();
        int vid = E[v].size();

        E[u].push_back({v, f, vid});
        E[v].push_back({u, 0, uid});
    }

    int sm = 0;
    while(bfs()) {
        sm += dfs(S, INF);
    }
    cout << sm << '\n';

    return 0;
}
