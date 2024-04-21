#include <iostream>
#include <queue>
#include <vector>
using namespace std;


const int INF = 0x3f3f3f3f;
int N;
int S, T, C;
vector<vector<int> > G;
vector<int> parents;
void init() {
    G.resize(N+1);
    parents.resize(N+1);
    for(auto &i: G) i.resize(N+1, 0);
}
bool bfs(int from, int to) {
    vector<bool> visited(N+1);
    queue<int> q({from});
    visited[from] = true;
    while (not q.empty()) {
        int u = q.front(); q.pop();
        for (int i=1;i<=N;++i) {
            if (visited[i] or G[u][i] <= 0)
                continue;

            parents[i] = u;
            visited[i] = true;
            q.push(i);
            if (i == to) {
                return true;
            }
        }
    }
    return false;
}
int ford_fulkerson() {
    int max_flow = 0;
    while (bfs(S, T)) {
        int path_flow = INF;
        for (int pointer=T;pointer!=S;pointer=parents[pointer]) {
            path_flow = min(path_flow, G[parents[pointer]][pointer]);
        }
        for (int pointer=T;pointer!=S;pointer=parents[pointer]) {
            G[parents[pointer]][pointer] -= path_flow;
            G[pointer][parents[pointer]] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}
int main() {
    int kase = 1;
    while(cin >> N and N) {
        cin >> S >> T >> C;
        init();
        for(int i=0;i<C;++i) {
            int a, b, c;
            cin >> a >> b >> c;
            G[a][b] += c;
            G[b][a] += c;
        }
        cout << "Network " << kase++ << '\n';
        cout << "The bandwidth is " << ford_fulkerson() << ".\n";
    }
    return 0;
}
