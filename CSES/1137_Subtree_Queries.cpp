#include <iostream>
#include <vector>
using namespace std;
#define int int64_t


const int maxn = 2e5 + 5;
int d[maxn]={0};
int f[maxn]={0};
int sm[maxn<<2]={0};
vector<int> adj[maxn];
int N, Q;
void dfs(int u, int pre) {
    static int ts = 0;
    d[u] = ++ts;
    for(int v: adj[u]) {
        if(v==pre) continue;
        dfs(v, u);
    }
    f[u] = ts;
}
void update(int pos, int x, int u, int ul, int ur) {
    if(ul==ur) {
        sm[u] = x;
        return;
    }

    int mid = (ur-ul)/2+ul;
    if(pos<=mid) {
        update(pos, x, u<<1, ul, mid);
    } else {
        update(pos, x, u<<1|1, mid+1, ur);
    }
    sm[u] = sm[u<<1]+sm[u<<1|1];
}
int query(int l, int r, int u, int ul, int ur) {
    if(l<=ul and ur<=r) {
        return sm[u];
    }
    int q(0);
    int mid = (ur-ul)/2+ul;
    if(l<=mid) {
        q += query(l, r, u<<1, ul, mid);
    }
    if(mid+1<=r) {
        q += query(l, r, u<<1|1, mid+1, ur);
    }
    return q;
}
void update(int pos, int x) {
    return update(pos, x, 1, 1, N);
}
int query(int l, int r) {
    return query(l, r, 1, 1, N);
}
signed main() {
    cin >> N >> Q;
    vector<int> Nums(N);
    for(auto &i: Nums) cin >> i;
    for(int i=0;i<N-1;++i) {
        int a, b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    dfs(1, -1);
    for(int i=0;i<N;++i) {
        update(d[i+1], Nums[i]);
    }
    while(Q--) {
        int op, s, x;
        cin >> op;
        if(op==1) {
            cin >> s >> x;
            update(d[s], x);
        } else {
            cin >> s;
            cout << query(d[s], f[s]) << '\n';
        }
    }


    return 0;
}
