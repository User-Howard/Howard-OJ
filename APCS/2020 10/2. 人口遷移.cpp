// 10 mins
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
#define fi first
#define se second

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
const int INF = 2e9;
int main() {
    int R, C, K, M;
    cin >> R >> C >> K >> M;
    vector<vector<pii> > P(R+2, vector<pii>(C+2, {-1, 0}));
    for(int i=1;i<=R;++i)
        for(int j=1;j<=C;++j) cin >> P[i][j].fi;
    
    while(M--) {
        for(int i=1;i<=R;++i) {
            for(int j=1;j<=C;++j) {
                for(int k=0;k<4;++k) {
                    int x = i+dx[k], y = j+dy[k];
                    if(P[x][y].fi == -1) continue;

                    P[x][y].se += P[i][j].fi / K;
                    P[i][j].se -= P[i][j].fi / K;
                }
            }
        }
        for(int i=1;i<=R;++i) {
            for(int j=1;j<=C;++j) {
                P[i][j].fi += P[i][j].se;
                P[i][j].se = 0;
            }
        }
    }
    int mi = INF, mx = -INF;
    for(int i=1;i<=R;++i) {
        for(int j=1;j<=C;++j) {
            if(P[i][j].fi == -1) continue;
            mi = min(mi, P[i][j].fi);
            mx = max(mx, P[i][j].fi);
        }
    }
    cout << mi << '\n' << mx << '\n';
    return 0;
    
}