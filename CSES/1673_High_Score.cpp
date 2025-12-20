// cleaner code from https://github.com/mrsac7/CSES-Solutions/blob/master/src/1673%20-%20High%20Score.cpp
#include <iostream>
#include <vector>
#include <tuple>
#include <set>
#include <queue>
using namespace std;
#define int int64_t
#define all(x) x.begin(),x.end()
#define mp make_pair
#define eb emplace_back

const int MAX_N = 2500+5;
const int INF = 1e18;
int N, M;
vector<tuple<int, int, int> > E;
vector<int> adj[MAX_N];
vector<int> adj2[MAX_N];
vector<int> V(MAX_N, -INF);
vector<bool> vis(MAX_N, false);
vector<bool> vis2(MAX_N, false);
void dfs(int x) {
    if(vis[x]) return;
    vis[x] = true;
    for(int v: adj[x]) dfs(v);
}
void dfs2(int x) {
    if(vis2[x]) return;
    vis2[x] = true;
    for(int v: adj2[x]) dfs2(v);
}
int solve() {
    V[1] = 0;
    for(int i=1;i<=N;++i) {
        int last_score = V[N];
        for(auto [u, v, d]: E) {
            if(V[v] >= V[u]+d) continue;
            if(i==N and vis[v] and vis2[v]) return -1;
            V[v] = V[u]+d;
        }
    }
    return V[N];
}
signed main() {
    cin >> N >> M;
    while(M--) {
        int u, v, d;
        cin >> u >> v >> d;
        E.eb(u, v, d);
        adj[u].emplace_back(v);
        adj2[v].emplace_back(u);
    }
    dfs(1);
    dfs2(N);
    cout << solve() << '\n';
    return 0;
}
