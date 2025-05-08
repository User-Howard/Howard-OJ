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
    int T;
    cin >> T;
    while(T--) {
        int V, N;
        cin >> V >> N;
        vector<int> dp(2e5, INF);
        dp[0] = 0;
        for(int i=0;i<N;++i) {
            int x;
            cin >> x;
            for(int j=2e5-1;j>=x;--j) {
                dp[j] = min(dp[j-x]+1, dp[j]);
            }
        }
        for(int i=V;i<2e5;++i) {
            if(dp[i]!=INF) {
                cout << i << ' ' << dp[i] << '\n';
                break;
            }
        }
    }
    return 0;
}