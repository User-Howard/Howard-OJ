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
    int N;
    while(cin >> N and N) {
        vector<int> Nums(N);
        for(auto &i: Nums) cin >> i;
        vector<int> ans(N);
        vector<int> dp;
        vector<int> id;
        for(int i=0;i<N;++i) {
            if(dp.empty() or dp.back()<Nums[i]) { 
                if(size(id))
                    ans[i] = id.back();
                else ans[i] = -1;
                dp.push_back(Nums[i]);
                id.push_back(i);
                continue;
            }
            int result = distance(dp.begin(), lower_bound(all(dp), Nums[i]));
            id[result] = i;
            dp[result] = Nums[i];
            if(result) ans[i] = id[result-1];
            else ans[i] = -1;
        }
        int ptr = id.back();
        vector<int> lis;
        while(ans[ptr]!=-1) {
            lis.push_back(Nums[ptr]);
            ptr = ans[ptr];
        }
        lis.push_back(Nums[ptr]);
        reverse(all(lis));
        cout << lis.size() << ' ';
        for(auto &i: lis) cout << i << ' ';
        cout << '\n';
    }
    
    return 0;
}