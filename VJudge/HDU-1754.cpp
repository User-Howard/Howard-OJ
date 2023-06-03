#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


int N, M;
vector<int> scores(200000<<2);
void pull(int u) {
    scores[u] = max(scores[u<<1], scores[u<<1|1]);
}
void build(int u, int l, int r) {
    if(l == r) {
        cin >> scores[u];
        return;
    }
    int mid = (l + r) >> 1;
    build(u<<1, l, mid);
    build(u<<1|1, mid+1, r);
    pull(u);
}
void update(int u, int l, int r, int pos, int x) {
    if(l==r) {
        scores[u] = x;
        return;
    }
    int mid = (l+r) >> 1;
    if(pos <= mid) update(u<<1, l, mid, pos, x);
    else update(u<<1|1, mid+1, r, pos, x);
    pull(u);
}
int query(int u, int l, int r, int ql, int qr) {
    if(ql <= l and r <= qr) {
        return scores[u];
    }
    int mid = (l+r) >> 1;
    int ans = -1;
    if(ql <= mid) ans = max(ans, query(u<<1, l, mid, ql, qr));
    if(mid < qr) ans = max(ans, query(u<<1|1, mid+1, r, ql, qr));
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> N >> M) {
        for(int i=0;i<N;++i) {
            int a;
            cin >> a;
            update(1, 0, N-1, i, a);
        }
        char c;
        int a, b;
        while(M--) {
            cin >> c >> a >> b;
            if(c=='U') {
                update(1, 0, N-1, a-1, b);
            } else {
                cout << query(1, 0, N-1, a-1, b-1) << '\n';
            }
        }
    }
    return 0;
}