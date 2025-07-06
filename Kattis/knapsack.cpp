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
    // quick
    int C, N;
    while(cin >> C >> N) {
        vector<vector<int> > dp(N+1, vector<int>(C+1, -INF));
        vector<int> cost(N);
        dp[0][0] = 0;
        for(int i=0;i<N;++i) {
            int v, c;
            cin >> v >> c;
            cost[i] = c;
            for(int j=C;j>=0;--j) {
                dp[i+1][j] = dp[i][j];
                if(j-c>=0 and dp[i][j-c]+v>dp[i][j]) {
                    dp[i+1][j] = dp[i][j-c]+v;
                }
            }
        }
        int ans_id = 0;
        for(int i=1;i<=C;++i) {
            if(dp[N][i]>dp[N][ans_id]) ans_id = i;
        }
        int ptr = ans_id;
        vector<int> ans;
        for(int i=N;i>0;--i) {
            if(dp[i][ptr]!=dp[i-1][ptr]) {
                ans.push_back(i-1);
                ptr -= cost[i-1];
            }
        }
        cout << size(ans) << '\n';
        for(int i: ans) cout << i << ' ';
        cout << '\n';
    }
    
    return 0;
}