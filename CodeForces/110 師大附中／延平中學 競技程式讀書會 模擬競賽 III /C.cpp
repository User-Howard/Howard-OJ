#include <iostream>
#include <deque>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;


vi visit, path;
vvi G;
void dfs(int x) {
    visit[x] = 1;
    path.push_back(x);
    for(int i:G[x]) {
        if(visit[i] == 2) continue;
        if(visit[i] == 1) {
            bool p = false;
            for(int j=0;j<path.size();++j) {
                if(path[j] == i) {
                    p = true;
                    cout << path.size() - j << '\n';
                }
                if(p) cout << path[j] << ' ';
            }
            cout << '\n';
            exit(0);
        }
        if(visit[i] == 0) {
            dfs(i);
            continue;
        }
    }
    visit[x] = 2;
    path.pop_back();
}
int main() {
    int N, M;
    cin >> N >> M;
    visit.resize(N+1);
    G.resize(N+1);
    for(int i=0;i<M;++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    for(int i=1;i<=N;++i) {
        if(!visit[i]) dfs(i);
    }
    cout << "-1" << '\n';
    return 0;
}