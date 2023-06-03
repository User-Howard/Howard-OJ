#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


int N;
vector<int64_t> scores(50000<<2);
void pull(int u) {
    scores[u] = scores[u<<1] + scores[u<<1|1];
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
        scores[u] += x;
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
    int64_t ans = 0;
    if(ql <= mid) ans += query(u<<1, l, mid, ql, qr);
    if(mid < qr) ans += query(u<<1|1, mid+1, r, ql, qr);
    return ans;
}
void solve() {
    cin >> N;
    build(1, 0, N-1);
    string c;
    int a, b;
    while(true) {
        cin >> c;
        if(c == "End")
            break;
        cin >> a >> b;
        if (c == "Add")
            update(1, 0, N-1, a-1, b);
        else if (c == "Sub")
            update(1, 0, N-1, a-1, -b);
        else if (c == "Query")
            cout << query(1, 0, N-1, a-1, b-1) << '\n';
    }

}
int main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    for(int i=1;i<=T;++i) {
        cout << "Case " << i << ":\n";
        solve();
    }
    return 0;
}