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
    int N;
    cin >> N;
    int D[2020];
    int votes[2020];
    for(int i=0;i<N;++i) {
        int c, f, u;
        cin >> D[i] >> c >> f >> u;
        if(c+u<=f) {
            votes[i] = INF;
        } else if(c>f+u) {
            votes[i] = 0;
        } else {
            votes[i] = (f-c+u)/2 + 1;
        }
        // cerr <<votes[i] << '\n';
    }
    int dp[2020];
    fill(dp, dp+2020, INF);
    dp[0] = 0;
    for(int i=0;i<N;++i) {
        for(int j=2019;j-D[i]>=0;--j) {
            dp[j] = min(dp[j], dp[j-D[i]]+votes[i]);
        }
    }

    int total_delegates = 0;
    for(int i=0;i<N;++i) total_delegates += D[i];
    int ans = *min_element(dp+total_delegates/2+1, dp+2020);
    if(ans == INF) {
        cout << "impossible\n";
    } else {
        cout << ans << '\n';
    }
    return 0;
}