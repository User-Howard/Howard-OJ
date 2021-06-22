#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;


int N, M;
vector<vector<int> >G(0);
vector<int>color(0);
bool dfs(int x, int c){
    color[x] = c;
    for(int v:G[x]){
        if(!color[v]){
            if(!dfs(v, -c)) return false;
        }
        else if(color[v]==c) return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> N >> M && N){
        G.resize(N);
        color.resize(N);
        for (int i = 0;i < N;i++) {
            G [i].clear();
            color [i] = 0;
        }
        for (int i=0, a, b;i<M;i++) {
            cin >> a >> b;
            G[a-1].push_back(b-1);
            G[b-1].push_back(a-1);
        }
        cout << (dfs(0, 1) ? "Yes" : "No") << '\n';
    }
    return 0;
}