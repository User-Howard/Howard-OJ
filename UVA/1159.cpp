#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
using namespace std;
#define int uint64_t

const int maxn = 1e5 + 5;
const int inf = 1e9 + 5;
int N, M;
vector<pair<int, int> > G[maxn];
int mp[maxn];
void bfs1() {
    fill(mp, mp+maxn, -1);
    mp[N] = 0;
    queue<pair<int, int> > que({{N, 0}});
    while(not que.empty()) {
        auto [u, dis] = que.front(); que.pop();
        for(auto [v, ndis]: G[u]) {
            if(mp[v]==-1) {
                mp[v] = dis+1;
                que.emplace(v, dis+1);
            }
        }
    }
}
void solve() {
    int distance_to_end = mp[1];
    set<pair<int, int> > from = {{1, distance_to_end}};
    cout << distance_to_end << '\n';
    bool flag = true;
    while(distance_to_end--) {
        set<pair<int, int> > to;
        int min_color = inf;
        for(auto [u, _]: from) {
            for(auto [v, ndis]: G[u]) {
                if(mp[v]!=distance_to_end) continue;
                min_color = min(min_color, ndis);
            }
        }
        for(auto [u, _]: from) {
            for(auto [v, ndis]: G[u]) {
                if(mp[v]!=distance_to_end) continue;
                if(ndis!=min_color) continue;
                to.emplace(v, ndis);
            }
        }
        if(flag) {
            flag = false;
        } else {
            cout << ' ';
        }
        cout << min_color;
        swap(from, to);
    }
    cout << '\n';
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    while(cin >> N >> M) {
        for(int i=1;i<=N;++i) {
            G[i].clear();
        }

        while(M--) {
            int a, b, c;
            cin >> a >> b >> c;
            G[a].emplace_back(b, c);
            G[b].emplace_back(a, c);
        }
        bfs1();
        solve();
    }
    return 0;
}
