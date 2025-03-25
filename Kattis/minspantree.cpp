#pragma GCC optimzize("Ofast,no-stack-protector")
#include <iostream>
#include <algorithm>
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
const int MAX_N = 2e4+5;

int N, M;
int pa[MAX_N];
void init() {
    for(int i=0;i<MAX_N;++i) {
        pa[i] = i;
    }
}
int find(int x) {
    if(pa[x]==x) return x;
    return pa[x] = find(pa[x]);
}
int findpa(int x) {
    if(pa[x] == x) return x;
    return pa[x] = findpa(pa[x]);
}
auto solve() {
    priority_queue<tuple<int, int, int> > edges;
    vector<tuple<int, int, int> > answer; 
    for(int i=0;i<M;++i) {
        int a, b, d;
        cin >> a >> b >> d;
        edges.push({-d, -a, -b});
    }
    while(not edges.empty() and answer.size()<N-1) {
        auto [d, u, v] = edges.top(); edges.pop(); d *= -1, u *= -1, v *= -1;
        int pu = findpa(u);
        int pv = findpa(v);
        if(pu==pv) continue;
        pa[pu] = pv;
        if(u>v) swap(u, v);
        answer.push_back({u, v, d});
    }
    return answer;
}
signed main(){
    quick
    while(cin >> N >> M and N) {
        init();
        auto answer = solve();
        if(answer.size()!=N-1) {
            cout << "Impossible\n";
            continue;
        }
        sort(all(answer));
        int min_sum = 0;
        for(auto [u, v, d]: answer)
            min_sum += d;
        cout << min_sum << '\n';
        for(auto [u, v, d]: answer) {
            cout << u << ' ' << v << '\n';
        }
    }
    return 0;
}