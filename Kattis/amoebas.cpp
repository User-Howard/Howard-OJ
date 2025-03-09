#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool> > visited(100, vector<bool>(100));
vector<vector<bool> > ct(100, vector<bool>(100));
int N, M;
void solve(int x, int y) {
    if(visited[x][y]) return;
    visited[x][y] = 1;
    for(int i=-1;i<=1;++i) {
        for(int j=-1;j<=1;++j) {
            if(x+i<0 or x+i>=N) continue;
            if(y+j<0 or y+j>=M) continue;
            if(ct[x+i][y+j])
                solve(x+i, y+j);
        }
    }
}
signed main(){
    cin >> N >> M;
    for(int i=0;i<N;++i) {
        string s;
        cin >> s;
        for(int j=0;j<M;++j) {
            ct[i][j] = s[j]== '#';
        }
    }
    int ans = 0;
    for(int i=0;i<N;++i) {
        for(int j=0;j<M;++j) {
            if(visited[i][j]) continue;
            if(!ct[i][j]) continue;
            solve(i, j);
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}