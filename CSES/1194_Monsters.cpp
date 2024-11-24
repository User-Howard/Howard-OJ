#include <iostream>
#include <vector>
#include <queue>
using namespace std;


const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
const int dc[4] = {'U', 'L', 'R', 'D'};
int N, M;
const int INF = 1e9;
string Map[1000];
int MonsterMap[1000][1000];
void updateMonsterMap(int x, int y, int step=0) {
    MonsterMap[x][y] = step;
    for(int i=0;i<4;++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0 or ny<0 or nx>=N or ny>=M) continue;
        if(Map[nx][ny]=='#') continue;
        if(MonsterMap[nx][ny] <= step+1) continue;
        updateMonsterMap(nx, ny, step+1);
    }
}
string bfs(int x, int y) {
    queue<pair<int, int> > q;
    queue<int> step;
    queue<string> path;
    bool visited[1000][1000] = {0};
    q.push({x, y});
    path.push("");
    step.push(0);
    visited[x][y] = 1;
    while(not q.empty()) {
        int rx = q.front().first;
        int ry = q.front().second;
        int s = step.front();
        string p = path.front();
        q.pop();
        step.pop();
        path.pop();
        for(int i=0;i<4;++i) {
            int nx = rx + dx[i];
            int ny = ry + dy[i];
            if(Map[nx][ny] == '#' or visited[nx][ny]) continue;
            if(MonsterMap[nx][ny] <= s+1) continue;
            if(nx==0 or ny==0 or nx==N-1 or ny==M-1) return p+(char)dc[i];
            visited[nx][ny] = 1;
            q.push({nx, ny});
            path.push(p+(char)dc[i]);
            step.push(s+1);
            // cerr << nx << ' ' << ny << ' ' << p+(char)dc[i] << "when" << MonsterMap[nx][ny] << " and " << s << '\n';
        }
    }
    return "";
}
int main() {
    // freopen("in", "r", stdin);
    cin >> N >> M;
    for(int i=0;i<N;++i)
        cin >> Map[i];

    for(int i=0;i<N;++i) {
        for(int j=0;j<M;++j) {
            MonsterMap[i][j] = INF;
        }
    }
    pair<int, int> player;
    for(int i=0;i<N;++i) {
        for(int j=0;j<M;++j) {
            if(Map[i][j] == 'A') {
                player = {i, j};
            }
            if(Map[i][j]=='M') {
                // cout << "OS\n";
                updateMonsterMap(i, j);
            }
        }
    }
    if(player.first==0 or player.second==0 or player.first==N-1 or player.second==M-1) {
        cout << "YES\n0\n";
        return 0;
    }
    string q = bfs(player.first, player.second);
    if(q != "") {
        cout << "YES\n" << q.size() << '\n' << q << '\n';
    } else {
        cout << "NO\n";
    }
    return 0;
}
