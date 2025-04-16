#pragma GCC optimzize("Ofast,no-stack-protector")
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
const int MAX_N = 1e6+5;
const int INF=1e18;

int N, M, A, C;
int X[MAX_N];
bool solve(int l, int r, int value) {
    if(l>r) return false;
    int mid = l+(r-l)/2;
    if(X[mid]==value) return true;
    if(X[mid] < value) {
        return solve(mid+1, r, value);
    } else {
        return solve(l, mid-1, value);
    }
}
signed main(){
    quick
    cin >> N >> M >> A >> C >> X[0];
    for(int i=1;i<=N;++i) {
        X[i] = (A*X[i-1]+C)%M;
    }
    int ans=0;
    for(int i=1;i<=N;++i) {
        if(solve(1, N, X[i])) {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}