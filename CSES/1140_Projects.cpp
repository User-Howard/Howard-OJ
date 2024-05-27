#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <tuple>
using namespace std;

int N;
set<int> st;
vector<tuple<int, int, int> > Ranges;
vector<uint64_t> dp;
bool cmp(tuple<int, int, int> &a, tuple<int, int, int> &b) {
    if(get<1>(a)==get<1>(b)) {
        return get<0>(a) < get<0>(b);
    } else {
        return get<1>(a) < get<1>(b);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;++i) {
        int f, t, d;
        cin >> f >> t >> d;
        Ranges.push_back(make_tuple(f, t, d));
        st.insert(f);
        st.insert(t);
    }
    map<int, int> mp;
    int cnt=1;
    for(int i: st) {
        mp[i] = cnt++;
    }
    for(int i=0;i<N;++i) {
        get<0>(Ranges[i]) = mp[get<0>(Ranges[i])];
        get<1>(Ranges[i]) = mp[get<1>(Ranges[i])];
    }
    sort(Ranges.begin(), Ranges.end(), cmp);

    dp.resize(cnt);
    int rec = 0;
    for(int i=1;i<cnt;++i) {
        dp[i] = dp[i-1];
        for(int j=rec;j<N;++j) {
            if(get<1>(Ranges[j]) < i) {
                rec = j+1;
                continue;
            }
            if(i < get<1>(Ranges[j])) {
                break;
            }
            dp[i] = max(dp[i], dp[get<0>(Ranges[j])-1]+get<2>(Ranges[j]));
        }
    }
    /*
    for(int i=0;i<cnt;++i)
        cout << i << '\t';
    cout << '\n';
    for(int i=0;i<cnt;++i)
        cout << dp[i] << '\t';
    cout << '\n';
    */
    cout << dp.back() << '\n';
    return 0;
}
