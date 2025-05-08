#pragma GCC optimize("Ofast,no-stack-protector")
#include <bits/stdc++.h>
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

signed main(){
    quick
    int N, K;
    cin >> N >> K;
    multiset<int> classroom;
    vector<pii> T(N);
    for(auto &i: T) cin >> i.first >> i.second;
    sort(all(T), [](const pii &a, const pii &b) {
        return a.second < b.second;
    });

    for(int i=0;i<K;++i) classroom.insert(0);

    int ans = 0;
    for(auto i: T) {
        if(auto room=classroom.lower_bound(i.first); room!=classroom.begin()) {
            int time = *prev(room);
            classroom.erase(prev(room));
            ans++;
            classroom.insert(i.second);
        }
    }
    cout << ans << '\n';
    return 0;
}