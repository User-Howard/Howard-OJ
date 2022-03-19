#include <iostream>
#include <queue>
using namespace std;


int H, W;
char puzzle[105][105];
const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, 1, -1, 0};
int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> H >> W;
        int sx, sy, ex, ey;
        for(int i=0;i<H;++i){
            string s;
            cin >> s;
            for(int j=0;j<W;++j){
                puzzle[i][j] = s[j];
                if(puzzle[i][j] == 'K')
                    sx = i, sy = j;
                else if(puzzle[i][j] == '@')
                    ex = i, ey = j;
            }
        }
        queue<pair<int, pair<int, int> > > que;
        que.push(make_pair(0, make_pair(sx, sy)));
        while(!que.empty()){
            int step = que.front().first;
            int x = que.front().second.first, y = que.front().second.second;
            // cout << x << ' ' << y << '\n';
            que.pop();
            for(int i=0;i<4;++i){
                int rx = x + dx[i], ry = y + dy[i];
                if(puzzle[rx][ry] == '@'){
                    cout << step + 1 << '\n';
                    goto END;
                }
                else if(puzzle[rx][ry] != '#'){
                    puzzle[rx][ry] = '#';
                    que.push(make_pair(step+1, make_pair(rx, ry)));
                }
            }
        }
        cout << "= =\"" << '\n';
        END:;
    }
    return 0;
}