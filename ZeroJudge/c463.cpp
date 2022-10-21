#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

#define int uint64_t
typedef pair<int, int> pii;
typedef vector<vector<int> > vvi;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

int N;
vvi G;
vi in;
pii walk(int u) {
    if(G[u].empty()) {
        return mp(0, 1);
    }
    pii ret = mp(0, 0); // first: sum ; second: depth
    for(int i:G[u]) {
        pii result = walk(i);
        ret.se = max(ret.se, result.se);
        ret.fi += result.fi;
    }
    return mp(ret.fi+ret.se, ret.se+1);
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    G.resize(N+1);
    in.resize(N+1);
    for(int i=1;i<=N;++i) {
        int r;
        cin >> r;
        G[i].resize(r);
        for(int j=0;j<r;++j) {
            cin >> G[i][j];
            in[G[i][j]]++;
        }
    }
    for(int i=1;i<=N;++i) {
        if(in[i] == 0) {
            cout << i << '\n';
            cout << walk(i).fi << '\n';
        }
    }
    return 0;
}