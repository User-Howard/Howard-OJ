#include <iostream>
#include <vector>
using namespace std;
// typedef __uint128_t ll;
typedef long long int ll;
#define int ll

const int MAX_N = 2e5+5;
int N, Q;
struct Node {
    int l, r;
    int mid;

    ll sum;
    ll lz;
};
vector<Node> tree(MAX_N<<2);
vector<int> nums(MAX_N, 0);

void build(int l, int r, ll u) {
    int m = (l+r)>>1;
    tree[u].l = l;
    tree[u].r = r;
    tree[u].mid = m;
    if(l == r) {
        tree[u].sum = nums[l];
        return;
    }
    build(l, m, u<<1);
    build(m+1, r, u<<1|1);
    tree[u].sum = tree[u<<1].sum + tree[u<<1|1].sum;
}
void modify(int pl, int pr, int x, int u) {
    //  cerr << "pl: " << pl << " pr: " << pr << " ul: " << tree[u].l << " ur: " << tree[u].r << '\n';
    if(pl<=tree[u].l and tree[u].r<=pr) {
        tree[u].sum += 1LL*(tree[u].r-tree[u].l+1)*x;
        if(tree[u].l!=tree[u].r) {
            tree[u].lz += x;
            // cerr << "\tadd Lazy Tag " << x << '\n';
        }
        return;
    }
    tree[u].sum += 1LL*(min(pr, tree[u].r)-max(pl, tree[u].l)+1)*x;
    if(tree[u].mid+1<=pr)
        modify(pl, pr, x, u<<1|1);
    if(pl<=tree[u].mid)
        modify(pl, pr, x, u<<1);
}
ll sumOf(int ql, int qr, ll u) {
    // cerr << "ql: " << ql << " qr: " << qr << "u: " << u << " ul: " << tree[u].l << " ur: " << tree[u].r << '\n';
    if(ql<=tree[u].l and tree[u].r<=qr) {
        return tree[u].sum;
    }
    if(tree[u].lz) {
        modify(tree[u].l, tree[u].r, tree[u].lz, u<<1);
        modify(tree[u].l, tree[u].r, tree[u].lz, u<<1|1);
        tree[u].lz = 0;
    }
    ll sumOfRange = 0;
    if(tree[u].mid+1<=qr) {
        sumOfRange += sumOf(ql, qr, u<<1|1);
    }
    if(ql<=tree[u].mid) {
        sumOfRange += sumOf(ql, qr, u<<1);
    }
    return sumOfRange;
}
signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    for(int i=1;i<=N;++i) {
        cin >> nums[i];
    }
    build(1, N, 1);
    while(Q--) {
        int op, a, b, n;
        cin >> op;
    // cerr << "SO FAR SO GOOD\n";
        if(op == 1) {
            cin >> a >> b >> n;
            modify(a, b, n, 1);
        } else {
            cin >> a;
            cout << sumOf(a, a, 1) << '\n';
        }
    }
    return 0;
}
