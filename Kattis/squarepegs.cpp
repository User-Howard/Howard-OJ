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
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> Nums(N);
    for(int &i: Nums) cin >> i;
    priority_queue<long double> r;
    for(int i=0;i<M;++i) {
        int x;
        cin >> x;
        r.push(-x);
    }
    for(int i=0;i<K;++i) {
        int x;
        cin >> x;
        r.push(-1.0*x/sqrt(2));
    }
    sort(all(Nums));
    int ans = 0;
    for(int i: Nums) {
        if(not r.empty() and -r.top()<i) {
            // cerr << i << '\n';
            r.pop();
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}