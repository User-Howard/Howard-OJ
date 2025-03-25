#pragma GCC optimzize("Ofast,no-stack-protector")
#include <iostream>
#include <queue>
#include <cstring>
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
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
int N, M;
int V[1005][1005];
bool visited[1005][1005];
bool valid(int x, int y) {
    return x>=0 and y>=0 and x<N and y<M;
}
bool solve(int d) {
    queue<pair<int, int> > q;
    for(int i=0;i<N;++i) {
        if(V[i][0] > d) continue;
        q.push(mp(i, 0));
        visited[i][0] = true;
    }
    while(not q.empty()) {
        auto u = q.front(); q.pop();
        for(int di=0;di<4;++di) {
            auto v = mp(u.first+dx[di], u.second+dy[di]);
            if(not valid(v.first, v.second)) continue;
            if(V[v.first][v.second]>d) continue;
            if(visited[v.first][v.second]) continue;
            if(v.second==M-1) {
                return true;
            }
            visited[v.first][v.second] = true;
            q.push(v);
        }
    }
    return false;
}
signed main(){
    quick
    cin >> N >> M;
    for(int i=0;i<N;++i) {
        for(int j=0;j<M;++j)
            cin >> V[i][j];
    }
    int l=-1, r=1e6;
    while(r-l>1) {
        memset(visited, 0, sizeof(visited));
        int mid = l+(r-l)/2;
        if(solve(mid)) {
            r = mid;
        } else{
            l = mid;
        }
    }
    cout << r << '\n';
    return 0;
}