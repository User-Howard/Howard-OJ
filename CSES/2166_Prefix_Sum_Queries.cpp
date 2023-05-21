#include <iostream>
#include <vector>
#include <string.h>
using namespace std;


const int MAX_N = 5e5 + 2;
int N, Q;
struct Node{
    int64_t sum, max_prefix;
    Node(int64_t _sum=0, int64_t _pre=0) {sum=_sum, max_prefix=_pre;}
};
vector<Node> Tree(MAX_N*4);
void update(int k, int64_t x) {
    k += N;
    Tree[k] = Node(x, x);
    k >>= 1;
    while(k >= 1) {
        Tree[k].sum = Tree[2*k].sum + Tree[2*k+1].sum;
        Tree[k].max_prefix = max(Tree[2*k].max_prefix, Tree[2*k].sum + Tree[2*k+1].max_prefix);
        k >>= 1;
    }
}
int64_t query(int a, int b) {
    a += N, b += N;
    Node L(0, 0), R(0, 0);
    while(a <= b) {
        if(a&1) {
            L = Node(L.sum + Tree[a].sum, max(L.max_prefix, L.sum + Tree[a].max_prefix));
            a++;
        }
        if(~b&1) {
            R = Node(R.sum + Tree[b].sum, max(Tree[b].max_prefix, Tree[b].sum + R.max_prefix));
            b--;
        }
        a >>= 1;
        b >>= 1;
    }
    return max(L.max_prefix, L.sum + R.max_prefix);
    // 這一段程式碼參考自
    // https://github.com/mrsac7/CSES-Solutions/blob/master/src/2166%20-%20Prefix%20Sum%20Queries.cpp
    // 超級厲害
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    for(int i=0;i<N;++i) {
        int x; cin >> x;
        update(i, x);
    }
    while(Q--) {
        int x, a, b;
        cin >> x >> a >> b;
        if(x == 1) {
            update(a-1, b);
        } else {
            cout << query(a-1, b-1) << '\n';
        }
    }
    return 0;
}