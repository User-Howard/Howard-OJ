#include <iostream>
#include <queue>
#include <set>
using namespace std;


typedef pair<int, int> pii;
struct E{
    int x, y;
    set<pii> used;
};
int N, M;
int puzzle[22][22];
queue<pii> que;
void solve(){
    while(!que.empty()) que.pop();
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> puzzle[i][j];
            if(puzzle[i][j]==2)
                que.push(make_pair(i, j));
        }
    }
    while(!que.empty()){

    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> N >> M && N && M)
        solve();
    return 0;
}