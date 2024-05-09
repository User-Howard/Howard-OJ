#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
 
 
string S[1005];
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
void dfs(int x, int y) {
    S[x][y] = '#';
    for(int i=0;i<4;++i) {
        int nx = x+dx[i], ny = y+dy[i];
        if(S[nx][ny] == '#') continue;
        dfs(nx, ny);
    }
}
int main() {
    int N, M;
    cin >> N >> M;
    for(int i=1;i<=N;++i) {
        string s;
        cin >> s;
        S[i] = '#' + s + '#';
    }
    S[0] = S[N+1] = string(M+2, '#');
    int answer = 0;
    for(int i=0;i<=N+1;++i) {
        for(int j=0;j<=M+1;++j) {
            if(S[i][j] == '#') continue;
            ++answer;
            dfs(i, j);
        }
    }
    cout << answer << '\n';
    return 0;
}
