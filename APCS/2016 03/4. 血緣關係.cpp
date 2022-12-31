#include <iostream>
#include <set>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<int> > vvi;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

const int INF = 0x3f3f3f3f;
const int MAX_N = 1e5+2;
int N;
struct E{
    pair<int, int> m;
    vector<int> child;
    bool gone;
    E() {
        m = mp(-1, -1);
        child.clear();
        gone = false;
    }
}G[MAX_N];
void init(){
    for(int i=0;i<N;++i){
        G[i] = E();
    }
}
pair<int, int> walk(int u){
    if(G[u].gone)
        return G[u].m;
    G[u].gone = true;
    G[u].m = mp(0, 0);
    for(int i:G[u].child) {
        int result = walk(i).first+1;
        if(result > G[u].m.fi) {
            G[u].m = mp(result, G[u].m.fi);
        } else if(result > G[u].m.se) {
            G[u].m = mp(G[u].m.fi, result);
        }
    }
    return G[u].m;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while (cin >> N){
        init();
        int T = 0;
        for(int i=0;i<N;++i)
            T ^= i;
        for(int i=0;i<N-1;++i){
            int a, b;
            cin >> a >> b;
            G[a].child.pb(b);
            T ^= b;
        }
        walk(T);
        int ans = -INF;
        for(int i=0;i<N;++i){
            ans = max(G[i].m.fi + G[i].m.se, ans);
        }
        cout << ans << '\n';
    }
    return 0;
}
