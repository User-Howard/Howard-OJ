#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define int int64_t
#define mp make_pair


const int maxn = 2505;
int N;
vector<int> G[maxn];


int dis[maxn];
int tree_size;
int block=-1;
int bfs(int x, int pre=-1) {
    queue<tuple<int, int, int> > que({{x, 0, -1}});
    pair<int, int> farthest;
    while(not que.empty()) {
        auto [u, d, pre] = que.front(); que.pop();
        if(farthest<mp(d, u))
            farthest = {d, u};
        dis[u] = max(d, dis[u]);
        for(int v: G[u]) {
            if(v==pre) continue;
            if(v==block) continue;
            que.push({v, d+1, u});
        }
    }
    return farthest.second;
}
int get_size(int x, int pre=-1) {
    int cnt=1;
    for(int v: G[x]) {
        if(v==pre) continue;
        cnt += get_size(v, x);
    }
    return cnt;
}
void init() {
    fill(dis, dis+maxn, -1);
    block = -1;
}
int ans=1e9;
int a, b, c, d;
void solve(int x, int pre=-1) {
    for(int v: G[x]) {
        if(v==pre) continue;
        init();
        block = v;
        bfs(bfs(bfs(x)));
        int minA=1e9;
        int maxA=0;
        int ra;
        for (int i = 1; i <= N; ++i) {
            if (dis[i] != -1) {
                if(minA>dis[i]) {
                    ra = i;
                }
                minA = min(minA, dis[i]);
                maxA = max(maxA, dis[i]);
            }
        }
        init();
        block = x;
        bfs(bfs(bfs(v)));
        int minB = 1e9;
        int maxB = 0;
        int rb;
        for (int i = 1; i <= N; ++i) {
            if (dis[i] != -1) {
                if(minB>dis[i]) {
                    rb = i;
                }
                minB = min(minB, dis[i]);
                maxB = max(maxB, dis[i]);
            }
        }
        // cerr << x << ' ' << v << ' ' << maxA << ' ' << maxB << ' ' << minA << ' ' << minB << '\n';
        if(max(max(maxA, maxB), minA+minB+1) <= ans) {
            a = x;
            b = v;
            c = ra;
            d = rb;
        }
        ans = min(ans, max(max(maxA, maxB), minA+minB+1));
        solve(v, x);
    }
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for(int i=0;i<N-1;++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    solve(1);
    cout << ans << '\n';
    cout << a << ' ' << b << '\n' << c << ' ' << d << '\n';
    return 0;
}