#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second


int N, M;
vector<vector<int> > G;
vector<int > color;
vector<pair<int, int> > R;
void walk(int u, int c=1) {
    if(color[u] == c) {
        return ;
    } else if(color[u] == -c) {
        cout << "NO" << '\n';
        exit(0);
    } else {
        color[u] = c;
        for(int i=0;i<G[u].size();++i)
            walk(G[u][i], -c);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    G.resize(N+1);
    color.resize(N+1);
    for(int u, v, i=0;i<M;++i) {
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
        R.pb(mp(u, v));
    }
    for(int i=1;i<=N;++i) {
        if(color[i] == 0) {
            walk(i);
        }
    }
    cout << "YES" << '\n';
    for(int i=0;i<M;++i) {
        cout << (bool)(color[R[i].fi] == 1); 
    }
    cout << '\n';
    return 0;
}