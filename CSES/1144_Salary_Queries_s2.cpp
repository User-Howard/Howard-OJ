#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
#define int int64_t
typedef pair<int, int> pii;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    Tree<pii> st;
    int N, M;
    cin >> N >> M;
    vector<int> Nums(N);
    for(int i=0;i<N;++i) {
        cin >> Nums[i];
        st.insert({Nums[i], i});
    }
    while(M--) {
        char op;
        cin >> op;
        if(op=='?') {
            int a, b;
            cin >> a >> b;
            cout << st.order_of_key({b+1, -1}) - st.order_of_key({a, -1}) << '\n';
        } else {
            int k, x;
            cin >> k >> x;
            st.erase({Nums[k-1], k-1});
            Nums[k-1] = x;
            st.insert({Nums[k-1], k-1});
        }
    }
    return 0;
}