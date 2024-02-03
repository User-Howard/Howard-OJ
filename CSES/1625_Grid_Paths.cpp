#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
using namespace std;


string S;
int answer = 0;
bool visited[9][9];
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
unordered_map<char, int> direction;
void solve(int x, int y, int step=0) {
    if(x<1 or y<1 or x>8 or y>8) return;
    if(x==7 and y==1 and step!=48) return;
    if(visited[x+1][y] and visited[x-1][y] and !visited[x][y+1] and !visited[x][y-1]) return;
    if(!visited[x+1][y] and !visited[x-1][y] and visited[x][y+1] and visited[x][y-1]) return;
    
    if(step==48) {
        ++answer;
        return;
    }

    visited[x][y] = true;
    if(S[step]!='?') {
        int t = direction[S[step]];
        int nx = x+dx[t], ny = y+dy[t];
        if(!visited[nx][ny]) {
            solve(nx, ny, step+1);
        }
    } else {
        for(int i=0;i<4;++i) {
            int nx = x+dx[i], ny = y+dy[i];
            if(visited[nx][ny]) continue;
            solve(nx, ny, step+1);
        }
    }
    visited[x][y] = false;
}
int main() {
    memset(visited, 0, sizeof(visited));
    direction['D'] = 0;
    direction['U'] = 1;
    direction['L'] = 2;
    direction['R'] = 3;
    for(int i=0;i<9;++i) {
        visited[0][i] = visited[8][i] = visited[i][0] = visited[i][8] = true;
    }

    cin >> S;
    solve(1, 1);
    cout << answer << '\n';
    return 0;
}