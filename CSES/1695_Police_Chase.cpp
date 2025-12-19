#include <iostream>
#include <queue>
using namespace std;
#define int int64_t


const int maxn = 5e2+5;
const int maxm = 2e3+5;
const int inf = 1e18;
int S, T;
struct Edge {
    int v, flow, rvid;
};
int level[maxm];
vector<Edge> E[maxn];
bool bfs() {
    fill(level, level+maxm, -1);
    level[S] = 0;
    queue<int> que({S});
    while(not que.empty()) {
        int u = que.front(); que.pop();
        for(auto e: E[u]) {
            if(e.flow<=0) continue;
            if(level[e.v]!=-1) continue;
            level[e.v] = level[u]+1;
            que.push(e.v);
        }
    }
    return level[T]!=-1;
}
int dfs(int u, int cap) {
    if(u==T) return cap;
    int sm = 0;
    for(auto& e: E[u]) {
        if(e.flow<=0) continue;
        if(level[e.v]!=level[u]+1) continue;
        int max_cap = min(cap, e.flow);
        int result = dfs(e.v, max_cap);
        sm += result;
        cap -= result;
        e.flow -= result;
        E[e.v][e.rvid].flow += result;
    }
    if(sm==0) {
        level[u] = -1;
    }
    return sm;
}
void add_edge(int u, int v, int w) {
    int u_id = E[u].size();
    int v_id = E[v].size();
    E[u].push_back({v, w, v_id});
    E[v].push_back({u, w, u_id});
}
signed main() {
    int N, M;
    cin >> N >> M;
    for(int i=0;i<M;++i) {
        int a, b;
        cin >> a >> b;
        add_edge(a, b, 1);
    }
    S = 1;
    T = N;
    while(bfs()) {
        dfs(S, inf);
    }
    vector<pair<int, int> > ans;
    for(int i=1;i<=N;++i) {
        if(level[i]==-1) continue;
        for(auto e: E[i]) {
            if(level[e.v]!=-1) continue;
            ans.emplace_back(i, e.v);
        }
    }
    cout << size(ans) << '\n';
    for(auto [u, v]: ans) {
        cout << u << ' ' << v << '\n';
    }


    return 0;
}
