#pragma GCC optimzize("Ofast,no-stack-protector")
#include <bits/stdc++.h>
#include <set>
#include <vector>
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

int solve() {
    int N;
    cin >> N;
    vector<int> Nums(N+1);
    vector<int> prefix(N+1);
    multiset<int> st;
    for(int i=1;i<=N;++i) {
        cin >> Nums[i];
        prefix[i] = prefix[i-1] + Nums[i];
    }
    int ans=0;
    for(int i=0;i<=N;++i) {
        ans += st.count(prefix[i]-47);
        st.insert(prefix[i]);
    }
    return ans;
}

signed main(){
    quick
    int T;
    cin >> T;
    while(T--) {
        cout << solve() << '\n';
    }
    return 0;
}