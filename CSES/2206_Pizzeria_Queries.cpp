#include <iostream>
using namespace std;
#define int int64_t

const int INF = 2e9;
const int MAX_N = 2e5 + 10;

int N, Q;

class SegTree {
    int mi[MAX_N << 2];
    int mi_num[MAX_N];

public:
    SegTree() {}

    void resize(int n) { mi_num[0] = mi_num[n + 1] = INF; }

    void update(int pos, int val, int u, int l, int r) {
        if (l == r) {
            mi[u] = val;
            mi_num[l] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid) update(pos, val, u << 1, l, mid);
        if (mid + 1 <= pos) update(pos, val, u << 1 | 1, mid + 1, r);
        mi[u] = min(mi[u << 1], mi[u << 1 | 1]);
    }

    void update(int pos, int val) { return update(pos, val, 1, 0, N + 1); }

    int query(int pl, int pr, int u, int l, int r) {
        if (l == r) {
            return mi[u];
        }
        if (pl <= l && r <= pr) {
            return mi[u];
        }
        int mid = l + (r - l) / 2;
        int ans = INF;
        if (pl <= mid) ans = min(ans, query(pl, pr, u << 1, l, mid));
        if (mid + 1 <= pr)
            ans = min(ans, query(pl, pr, u << 1 | 1, mid + 1, r));
        return ans;
    }

    int query(int pl, int pr) { return query(pl, pr, 1, 0, N + 1); }
};

SegTree rhs, lhs;
int num[MAX_N];

void update_all(int pos, int val) {
    rhs.update(pos, val + pos);
    lhs.update(pos, val - pos);
    num[pos] = val;
}

int solve(int pos) {
    int lans = lhs.query(0, pos);
    int rans = rhs.query(pos, N + 1);
    return min(lans + pos, rans - pos);
}

signed main() {
    cin >> N >> Q;
    rhs.resize(N);
    lhs.resize(N);
    update_all(0, INF);
    update_all(N + 1, INF);

    for (int i = 1; i <= N; ++i) {
        int x;
        cin >> x;
        update_all(i, x);
    }

    while (Q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int k, x;
            cin >> k >> x;
            update_all(k, x);
        } else {
            int k;
            cin >> k;
            cout << solve(k) << '\n';
        }
    }

    return 0;
}
