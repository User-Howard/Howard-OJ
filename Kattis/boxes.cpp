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

const int maxn = 2e5+5;
vector<int> Graph[maxn];
int N;
int solve() {
    int Q;
    cin >> Q;
    bitset<maxn> bt;
    for(int i=0;i<Q;++i) {
        int a;
        cin >> a;
        if(bt[a]) continue;
        queue<int> q;
        q.push(a);
        while(not q.empty()) {
            int u = q.front(); q.pop();
            bt[u] = true;
            for(int v: Graph[u]) {
                if(bt[v]) continue;
                bt[v] = true;
                q.push(v);
            }
        }
    }
    return bt.count();
}
signed main(){
    quick
    cin >> N;
    vector<int> Nums(N+1);
    for(int i=1;i<=N;++i) {
        cin >> Nums[i];
        Graph[Nums[i]].push_back(i);
    }
    int M;
    cin >> M;
    while(M--) {
        cout << solve() << '\n';
    }
    return 0;
}