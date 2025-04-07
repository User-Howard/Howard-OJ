#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <array>
using namespace std;
#define lowbit(x) x&-x
#define int int64_t

const int MAX_N = 2e5+5;
array<int, MAX_N> BIT;
array<int, MAX_N> Nums;
void update(int pos, int val) {
    for(;pos<MAX_N;pos+=lowbit(pos)) {
        BIT[pos] += val;
    }
}
int query(int pos) {
    int ans = 0;
    for(;pos>0;pos-=lowbit(pos)) {
        ans += BIT[pos];
    }
    return ans;
}
signed main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    int N;
    while(cin >> N, N) {
        static int kase = 1;
        set<int> st;
        unordered_map<int, int> mp;
        for(int i=0;i<N;++i) {
            cin >> Nums[i];
            st.insert(Nums[i]);
        }
        for(int i: st) {
            static int idx = 1;
            mp[i] = idx++;
        }
        int ans = 0;
        for(int i=N-1;i>=0;--i) {
            ans += query(mp[Nums[i]]-1);
            update(mp[Nums[i]], 1);
        }
        for(int i=0;i<N;++i) {
            update(mp[Nums[i]], -1);
        }
        cout << "Case #" << kase++ << ": " << ans << '\n';
    }
    return 0;
}