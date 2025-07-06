// #pragma GCC optimize("Ofast,no-stack-protector")
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

const int maxn = 2e5+5;
int N;
vector<int> G[maxn];

int dep[maxn];
int pos[maxn];
int tp=0;

int spt[maxn<<1][20];
void dfs(int x, int depth=0, int pre=-1) {
    dep[x] = depth;
    pos[x] = tp;
    spt[tp++][0] = dep[x];
    for(int v: G[x]) {
        if(v==pre) continue;
        dfs(v, depth+1, x);
        spt[tp++][0] = dep[x];
    }
}
signed main(){
    // quick
    cin >> N;
    for(int i=1;i<N;++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1);
    for(int i=1;i<20;++i){ 
        for(int j=0;j+(1<<i)<tp;++j) {
            spt[j][i] = min(spt[j][i-1], spt[j+(1<<(i-1))][i-1]);
        }
    }

    auto calculate_lengths = [](int xa, int xb) {
        int a = min(pos[xa], pos[xb]);
        int b = max(pos[xa], pos[xb]);
        int l = log2(b-a);
        int accDep = min(spt[a][l], spt[b-(1<<l)+1][l]);
        return dep[xa]+dep[xb]-2*accDep;
    };
    int ans = 0;
    for(int i=1;i<=N;++i) {
        for(int j=2;j*i<=N;++j) {
            ans += calculate_lengths(i, i*j)+1;
            // debug(i, i*j, calculate_lengths(i, i*j));
        }
    }
    cout << ans << '\n';
    return 0;
}