#include <iostream>
using namespace std;


int H, W;
bool ground[1005][1005];
const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, 1, -1, 0};
void dfs(int x, int y){
    ground[x][y] = true;
    for(int i=0;i<4;++i){
        if(!ground[x+dx[i]][y+dy[i]])
            dfs(x+dx[i], y+dy[i]);
    }
}
int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> H >> W;
        for(int i=0;i<H+2;++i)
            for(int j=0;j<W+2;++j)
                ground[i][j] = true;
        for(int i=1;i<=H;++i){
            string s;
            cin >> s;
            for(int j=1;j<=W;++j)
                ground[i][j] = (s[j-1] == '#');
        }
        int ans = 0;
        for(int i=1;i<=H;++i){
            for(int j=1;j<=W;++j){
                if(!ground[i][j]){
                    ans ++;
                    dfs(i, j);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}