#include <iostream>
using namespace std;


const int maxn = 105;
int N, M;
string S[maxn];
const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool available(int x, int y) {
    return x>=0 and x<N and y>=0 and y<M;
}
void solve() {
    for(int i=0;i<N;++i) {
        for(int j=0;j<M;++j) {
            if(S[i][j]=='*') {
                cout << '*';
                continue;
            }
            int cnt = 0;
            for(int d=0;d<8;++d) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if(not available(nx, ny)) continue;
                cnt += (S[nx][ny]=='*');
            }
            cout << cnt;
        }
        cout << '\n';
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int kase = 1;
    while(cin >> N >> M and N and M) {
        if(kase!=1) cout << '\n';
        cout << "Field #" << kase++ << ":\n";
        for(int i=0;i<N;++i) cin >> S[i];
        solve();
    }
    return 0;
}
