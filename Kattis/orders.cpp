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

const int maxn = 105;
int N, M;
int Nums[maxn];
int cnt[maxn][30010];
int dp[maxn][30010];
int from[maxn][30010];
signed main(){
    quick
    cin >> N;
    for(int i=0;i<N;++i) cin >> Nums[i];
    cin >> M;
    memset(cnt, 0, sizeof(cnt));
    cnt[0][0] = 1;
    for(int i=0;i<N;++i) {
        for(int j=0;j<30010;++j) {
            if(j>=Nums[i])
                cnt[i+1][j] += cnt[i+1][j-Nums[i]];
            cnt[i+1][j] += cnt[i][j];
        }
    }
    fill(&dp[0][0], &dp[0][0] + maxn * 30010, INF);
    dp[0][0] = 0;
    for(int i=0;i<N;++i) {
        // cout << Nums[i] << ":\t";
        for(int j=0;j<30010;++j) {
            if(j>=Nums[i])
                dp[i+1][j] = min(dp[i+1][j], dp[i+1][j-Nums[i]]+1);
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            // if(dp[i+1][j]==INF) cout << "INF\t";
            // else cout << dp[i+1][j] << '\t';
        }
        // cout << '\n';
    }
    while(M--) {
        int x;
        cin >> x;
        if(cnt[N][x]>1) {
            cout << "Ambiguous\n";
        } else if(cnt[N][x]==0) {
            cout << "Impossible\n";
        } else {
            int ptr = x;
            vector<int> ans;
            for(int i=N;i>0;--i) { 
                for(int j=0;ptr-j*Nums[i-1]>=0;j++) {
                    if(dp[i-1][ptr-j*Nums[i-1]]==dp[i][ptr]-j) {
                        ptr = ptr-j*Nums[i-1];
                        break;
                    }
                    ans.push_back(i);
                }
            }
            for(int i=size(ans)-1;i>=0;--i) cout << ans[i] << ' ';
            cout << '\n';
        }
    }
    return 0;
}