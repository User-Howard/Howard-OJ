#pragma GCC optimize("Ofast,no-stack-protector")
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#define int long long
#define quick ios::sync_with_stdio(0);cin.tie(0);
#define rep(x,a,b) for(int x=a;x<=b;x++)
#define repd(x,a,b) for(int x=a;x>=b;x--)
#define lowbit(x) (x&-x)
#define sz(x) (int)(x.size())
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define eb emplace_back
using namespace std;
typedef pair<int,int> pii;
void debug(){
    cout<<"\n";
}
template <class T,class ... U >
void debug(T a, U ... b){
    cout<<a<<" ",debug(b...);
}
const int maxn = 2e5+10;
const int INF=1e18;

vector<pii> adj[maxn];
int spider_dis[maxn];
int N, M, T;
int s, t;
void build() {
    fill(spider_dis, spider_dis+maxn, INF);
    priority_queue<pii> pq;
    pq.push(mp(0, maxn-1));
    spider_dis[maxn-1] = 0;
    while(not pq.empty()) {
        auto [d, u] = pq.top(); pq.pop(); d*=-1;
        if(spider_dis[u] < d) continue;
        for(auto [v, dd]: adj[u]) {
            if(spider_dis[v]>d+dd) {
                spider_dis[v] = d+dd;
                pq.push(mp(-d-dd, v));
            }
        }
    }
}
bool solvable(int x) {
    if(spider_dis[s]<x) return false;
    int dis[maxn];
    fill(dis, dis+maxn, INF);
    priority_queue<pii> pq;
    pq.push(mp(0, s));
    dis[s] = 0;
    while(not pq.empty()) { 
        auto [d, u] = pq.top(); pq.pop(); d*=-1;
        if(dis[u]<d) continue;
        for(auto [v, dd]: adj[u]) {
            if(spider_dis[v]<x) continue;
            if(dis[v]>d+dd) {
                dis[v] = d+dd;
                pq.push(mp(-d-dd, v));
            }
        }
    }
    return dis[t]<=T;
}
signed main(){
    quick
    cin >> N >> M >> T;
    for(int i=0;i<M;++i) {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back(mp(v, d));
        adj[v].push_back(mp(u, d));
    }
    cin >> s >> t;
    int K;
    cin >> K;
    for(int i=0;i<K;++i) {
        int x;
        cin >> x;
        adj[maxn-1].push_back(mp(x, 0));
        adj[x].push_back(mp(maxn-1, 0));
    }
    build();
    int l=0, r=INF;
    while(r-l>1) {
        int mid=l+(r-l)/2;
        if(solvable(mid)) {
            l=mid;
        } else {
            r=mid;
        }
    }
    cout << l << '\n';
    return 0;
}