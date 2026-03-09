#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;


using vpii = vector<pair<int, int> >;
using tiii = tuple<int, int, int>;
int dirt[100];
int dirx[100];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
const int maxn = 11;
vector<int> mp[maxn][maxn][4];
bool visited[maxn][maxn][4];
tiii rpath[maxn][maxn][4];
int sx, sy, ex, ey;
int end_direction=-1;
bool bfs(int px, int py, int pdir) {
    queue<tuple<int, int, int> > q;
    q.push({px, py, pdir});
    while(not q.empty()) {
        auto [x, y, dir] = q.front(); q.pop();
        if(x==ex and y == ey) {
            end_direction = dir;
            return true;
        }
        for(int ndir: mp[x][y][dir]) {
            if(visited[x+dx[ndir]][y+dy[ndir]][ndir]) continue;
            visited[x+dx[ndir]][y+dy[ndir]][ndir] = true;
            rpath[x+dx[ndir]][y+dy[ndir]][ndir] = {x, y, dir};
            q.push({x+dx[ndir], y+dy[ndir], ndir});
        }
    }
    return false;
}
vpii solve() {
    char dir;
    cin >> sx >> sy >> dir >> ex >> ey;
    int a, b;
    while(cin >> a and a) {
        cin >> b;

        string c;
        while(cin >> c and c!="*") {
            auto& vc = mp[a][b][dirt[c[0]]];
            for(int i=1;i<c.size();++i) {
                vc.push_back((4+dirt[c[0]] + dirx[c[i]])%4);
            }
        }
    }
    rpath[sx+dx[dirt[dir]]][sy+dy[dirt[dir]]][dirt[dir]] = {sx, sy, -1};
    if(not bfs(sx+dx[dirt[dir]], sy+dy[dirt[dir]], dirt[dir])) return vpii();

    vpii ans;
    auto cx = ex, cy = ey, cdir = end_direction;
    int cnt = 0;
    while(true) {
        ans.emplace_back(cx, cy);
        auto [nx, ny, ndir] = rpath[cx][cy][cdir];
        cx = nx, cy = ny, cdir = ndir;
        if(sx==cx and sy==cy) break;
    }
    ans.emplace_back(sx, sy);
    reverse(ans.begin(), ans.end());
    return ans;
}
void init() {
    dirt['N'] = 0;
    dirt['E'] = 1;
    dirt['S'] = 2;
    dirt['W'] = 3;


    dirx['L'] = -1;
    dirx['F'] = 0;
    dirx['R'] = +1;
    for(int i=0;i<maxn;++i) {
        for(int j=0;j<maxn;++j) {
            for(int k=0;k<4;++k) {
                visited[i][j][k] = false;
                mp[i][j][k].clear();
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string name;
    while(cin >> name and name!="END") {
        init();
        auto answer = solve();
        cout << name;
        if(answer.size()) {
            int cnt=0;
            for(auto i: answer) {
                if(cnt++%10==0) {
                    cout << "\n ";
                }
                cout << " (" << i.first << ',' << i.second << ")";
            }
            cout << '\n';
        } else {
            cout << "\n  No Solution Possible\n";
        }
    }
    return 0;
}
