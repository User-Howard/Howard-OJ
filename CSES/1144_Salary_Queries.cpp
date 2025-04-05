#include <iostream>
#include <unordered_map>
#include <set>
#include <tuple>
#include <vector>
using namespace std;
#define lowbit(x) (x&-x)
#define int int64_t
 
const int MAX_N = 6e5 + 10;
int BIT[MAX_N];
int Nums[MAX_N];
void update(int x, int v) {
    x+=2;
    for(;x<=MAX_N;x+=lowbit(x)) {
        BIT[x] += v;
    }
}
int query(int x) {
    x+=2;
    int ans=0;
    for(;x>0;x-=lowbit(x)) {
        ans += BIT[x];
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M;
    cin >> N >> M;
    set<int> st;
    for(int i=1;i<=N;++i) {
        cin >> Nums[i];
        st.insert(Nums[i]);
    }
    vector<tuple<char, int, int> > queries;
    for(int i=0;i<M;++i) {
        char op;
        int a, b;
        cin >> op >> a >> b;
        queries.push_back({op, a, b});
        if(op=='!') {
            st.insert(b);
        }
    }
    unordered_map<int, int> val2idx;
    st.insert(0);
    st.insert(1e9+10);
    for(int i: st) {
        static int idx = 1;
        val2idx[i] = idx++;
    }
    for(int i=1;i<=N;++i) {
        update(val2idx[Nums[i]], 1);
    }
    for(const auto& [op, a, b] : queries) {
        if(op == '!') {
            update(val2idx[Nums[a]], -1);
            Nums[a] = b;
            update(val2idx[Nums[a]], 1);
        } else {
            cout << query(val2idx[*prev(st.upper_bound(b))]) - query(val2idx[*prev(st.lower_bound(a))]) << '\n';
        }
    }
    return 0;
}