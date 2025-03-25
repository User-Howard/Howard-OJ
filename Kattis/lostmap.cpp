#pragma GCC optimzize("Ofast,no-stack-protector")
#include <iostream>
#include <queue>
#include <tuple>
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
const int MAX_N = 2505;

int N;
int V[MAX_N][MAX_N];
int pa[MAX_N];
int find(int x) {
    if(pa[x]==x) return x;
    return pa[x] = find(pa[x]);
}
signed main(){
    quick
    cin >> N;
    for(int i=0;i<N;++i) {
        for(int j=0;j<N;++j)
            cin >> V[i][j];
        pa[i] = i;
    }
    priority_queue<tuple<int, int, int> > pq;
    for(int i=0;i<N;++i) {
        for(int j=i+1;j<N;++j) {
            pq.push(make_tuple(-V[i][j], i, j));
        }
    }
    while(not pq.empty()) {
        auto [w, u, v] = pq.top(); pq.pop();
        if(find(u)==find(v)) continue;
        cout << u+1 << ' ' << v+1 << '\n';
        pa[find(u)] = find(v);
    }
    return 0;
}