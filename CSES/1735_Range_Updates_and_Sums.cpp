#include <iostream>
using namespace std;
#define int int64_t


const int maxn = 2e5 + 5;
int N, Q;
int SUM[maxn<<2];
int tag_add[maxn<<2];
int tag_set[maxn<<2];
void init() {
    fill(SUM, SUM+(maxn<<2), 0);
    fill(tag_add, tag_add+(maxn<<2), 0);
    fill(tag_set, tag_set+(maxn<<2), -1);
}
void apply_add(int u, int x, int ul, int ur) {
    SUM[u] += (ur-ul+1)*x;
    tag_add[u] += x;
}
void apply_set(int u, int x, int ul, int ur) {
    SUM[u] = (ur-ul+1)*x;
    tag_set[u] = x;
    tag_add[u] = 0;
}
void push_down(int u, int ul, int ur) {
    int mid = (ur-ul)/2+ul;
    if(tag_set[u]!=-1) {
        apply_set(u<<1, tag_set[u], ul, mid);
        apply_set(u<<1|1, tag_set[u], mid+1, ur);
        tag_set[u] = -1;
    }
    apply_add(u<<1, tag_add[u], ul, mid);
    apply_add(u<<1|1, tag_add[u], mid+1, ur);
    tag_add[u] = 0;
}
void pull_up(int u) {
    SUM[u] = SUM[u<<1] + SUM[u<<1|1];
}
void update_add(int l, int r, int x, int u, int ul, int ur) {
    if(l<=ul and ur<=r) {
        apply_add(u, x, ul, ur);
        return;
    }
    push_down(u, ul, ur);
    int mid = (ur-ul)/2+ul;
    if(l<=mid) {
        update_add(l, r, x, u<<1, ul, mid);
    }
    if(mid+1<=r) {
        update_add(l, r, x, u<<1|1, mid+1, ur);
    }
    pull_up(u);
}
void update_set(int l, int r, int x, int u, int ul, int ur) {
    if(l<=ul and ur<=r) {
        apply_set(u, x, ul, ur);
        return;
    }
    push_down(u, ul, ur);
    int mid = (ur-ul)/2+ul;
    if(l<=mid) {
        update_set(l, r, x, u<<1, ul, mid);
    }
    if(mid+1<=r) {
        update_set(l, r, x, u<<1|1, mid+1, ur);
    }
    pull_up(u);
}
int query(int l, int r, int u, int ul, int ur) {
    if(l<=ul and ur<=r) {
        return SUM[u];
    }
    push_down(u, ul, ur);
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
signed main() {
    init();
    cin >> N >> Q;
    for(int i=1;i<=N;++i) {
        int x;
        cin >> x;
        update_set(i, i, x, 1, 1, N);
    }
    while(Q--) {
        int op;
        int a, b, x;
        cin >> op >> a >> b;
        if(op==1) {
            cin >> x;
            update_add(a, b, x, 1, 1, N);
        } else if(op==2) {
            cin >> x;
            update_set(a, b, x, 1, 1, N);
        } else {
            cout << query(a, b, 1, 1, N) << '\n';
        }
    }

    return 0;
}
