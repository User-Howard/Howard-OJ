#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;
#define lowbit(x) (x&-x)
#define all(x) x.begin(),x.end()
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
    vector<int> st = {0};
    for(int i=1;i<=N;++i) {
        cin >> Nums[i];
        st.push_back(Nums[i]);
    }
    vector<tuple<char, int, int> > queries;
    for(int i=0;i<M;++i) {
        char op;
        int a, b;
        cin >> op >> a >> b;
        queries.push_back({op, a, b});
        if(op=='!') {
            st.push_back(b);
        }
    }
    sort(all(st));
    st.erase(unique(all(st)), st.end());
    auto getLowerIndex = [&st](int x) {
        return distance(st.begin(), lower_bound(all(st), x));
    };
    auto getPrevIndex = [&st](int x) {
        return distance(st.begin(), prev(upper_bound(all(st), x)));
    };
    for(int i=1;i<=N;++i) {
        update(getLowerIndex(Nums[i]), 1);
    }
    for(const auto& [op, a, b] : queries) {
        if(op == '!') {
            // cerr << Nums[a] << ":A " << getLowerIndex(Nums[a]) << '\n';
            update(getLowerIndex(Nums[a]), -1);
            Nums[a] = b;
            // cerr << Nums[a] << ":B " << getLowerIndex(Nums[a]) << '\n';
            update(getLowerIndex(Nums[a]), 1);
        } else {
            // cerr << a << ":C " << getLowerIndex(a)-1 << '\n';
            // cerr << b << ":D " << getPrevIndex(b) << '\n';
            cout << query(getPrevIndex(b)) - query(getLowerIndex(a)-1) << '\n';
        }
    }

    return 0;
}