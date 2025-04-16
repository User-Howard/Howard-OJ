#pragma GCC optimize("Ofast,no-stack-protector")
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#define int long long
#define quick ios::sync_with_stdio(0);cin.tie(0);
#define rep(x,a,b) for(int x=a;x<=b;x++)
#define repd(x,a,b) for(int x=a;x>=b;x--)
#define lowbit(x) (x&-x)
#define sz(x) (int)(x.size())
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define eb emplace_back
using namespace std;
typedef pair<int,int> pii;
void debug(){
    cout<<"\n";
}
template <class T,class ... U >
void debug(T a, U ... b){
    cout<<a<<" ",debug(b...);
}
const int INF=1e18;

string S;
set<int> nums;
map<int, vector<int> > G;
void solve(string s="", int x=1) {
    if(s.size()>3) {
        return;
    }
    if(s.size())
        nums.insert(stoi(s));
    solve(s+char(x+'0'), x);
    for(int v: G[x]) {
        solve(s, v);
    }
}
signed main(){
    quick
    G[1] = {2, 4};
    G[2] = {3, 5};
    G[3] = {6};
    G[4] = {5, 7};
    G[5] = {6, 8};
    G[6] = {9};
    G[7] = {8};
    G[8] = {9, 0};
    G[9] = {};
    solve();
    int T;
    cin >> T;
    while(T--) {
        int x;
        cin >> x;
        auto t = nums.upper_bound(x);
        int ans = INF;
        if(abs(x-ans)>(x-*t)) {
            ans = *t;
        }
        if(abs(x-ans)>(x-*prev(t))) {
            ans = *prev(t);
        }
        cout << ans << '\n';
    }
    return 0;
}