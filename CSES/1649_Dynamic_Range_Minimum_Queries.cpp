#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX_N = 2e5+5;
const int INF = 1e9;
int N, Q;
struct Node {
    int l, r;
    int mid;
    int min;
};
vector<Node> tree(MAX_N<<2);
vector<int> nums(MAX_N, 0);

void build(int l, int r, int u) {
    int m = (l+r)>>1;
    tree[u].l = l;
    tree[u].r = r;
    tree[u].mid = m;
    if(l == r) {
        tree[u].min = nums[l];
        return;
    }
    build(l, m, u<<1);
    build(m+1, r, u<<1|1);
    tree[u].min = min(tree[u<<1].min, tree[u<<1|1].min);
}
void modify(int pos, int x, int u) {
    if(tree[u].l == tree[u].r) {
        tree[u].min = x;
        return;
    }
    if(pos<=tree[u].mid)
        modify(pos, x, u<<1);
    else
        modify(pos, x, u<<1|1);
    tree[u].min = min(tree[u<<1].min, tree[u<<1|1].min);
}
int minOf(int ql, int qr, int u) {
    if(ql<=tree[u].l and tree[u].r<=qr) {
        return tree[u].min;
    }
    int minOfRange = INF;
    if(tree[u].mid+1<=qr) {
        minOfRange = min(minOf(ql, qr, u<<1|1), minOfRange);
    }
    if(ql<=tree[u].mid) {
        minOfRange = min(minOf(ql, qr, u<<1), minOfRange);
    }
    return minOfRange;
}
int  main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    for(int i=1;i<=N;++i) {
        cin >> nums[i];
    }
    build(1, N, 1);
    while(Q--) {
        int op, a, b;
        cin >> op >> a >> b;
        if(op == 1) {
            modify(a, b, 1);
        } else {
            cout << minOf(a, b, 1) << '\n';
        }
    }
    return 0;
}
