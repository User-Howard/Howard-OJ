#include <iostream>
using namespace std;

const int MAX_N = 2e5 + 5;
const int INF = 1e9 + 10;
int A[MAX_N<<2]={0};
int N, Q;
void init(int u, int l, int r) {
    A[u] = INF;
    if(l==r) return;
    int mid = (l + r) >> 1;
    init(2*u, l, mid);
    init(2*u+1, mid+1, r);
}
void update(int u, int l, int r, int ul, int ur, int x) {
    // cerr << "update " << u << ' ' << l << ' ' << r << ' ' << ul << ' ' << ur << ' ' << x << '\n';
    A[u] = min(A[u], x);
    if(l==r) return;
    int mid = (l + r) >> 1;
    if(ul<=mid) update(2*u, l, mid, ul, ur, x);
    if(mid+1<=ur) update(2*u+1, mid+1, r, ul, ur, x);
}
int query(int u, int l, int r, int ql, int qr) {
    // cerr << "query " << u << ' ' << l << ' ' << r << ' ' << ql << ' ' << qr << "::_>" << A[u] << '\n';
    if(ql<=l && r<=qr) {
        return A[u];
    }
    int mid = (l + r) >> 1;
    int res = INF;
    if(ql<=mid) res = min(res, query(2*u, l, mid, ql, qr));
    if(mid+1<=qr) res = min(res, query(2*u+1, mid+1, r, ql, qr));
    return res;
}
int main() {
    cin >> N >> Q;
    init(1, 1, N);
    for(int i=1;i<=N;++i) {
        int x;
        cin >> x;
        update(1, 1, N, i, i, x);
    }
    while(Q--) {
        int l, r;
        cin >> l >> r;
        cout << query(1, 1, N, l, r) << '\n';
    }
    return 0;
}
