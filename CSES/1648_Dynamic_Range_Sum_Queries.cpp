#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

const int MAX_N = 2e5+5;
int N, Q;
struct Node {
    int l, r;
    int mid;
    ll sum;
};
vector<Node> tree(MAX_N<<2);
vector<int> nums(MAX_N, 0);

void build(int l, int r, int u) {
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
void modify(int pos, int x, int u) {
    tree[u].sum += x;
    if(tree[u].l == tree[u].r) {
        return;
    }
    if(pos<=tree[u].mid) {
        modify(pos, x, u<<1);
    } else {
        modify(pos, x, u<<1|1);
    }
}
ll sumOf(int ql, int qr, int u) {
    if(ql<=tree[u].l and tree[u].r<=qr) {
        return tree[u].sum;
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
            modify(a, b-nums[a], 1);
            nums[a] = b;
        } else {
            cout << sumOf(a, b, 1) << '\n';
        }
    }
    return 0;
}
