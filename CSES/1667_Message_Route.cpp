#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


const int INF = 1e9;
const int MAX_N = 1e5 + 5;
int N, M;
int prevNode[MAX_N];
int minDistance[MAX_N];
vector<int> G[MAX_N];
int main() {
    cin >> N >> M;
    fill(minDistance, minDistance+N+1, INF);
    for(int i=0;i<M;++i) {
        static int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    minDistance[1] = 1;
    queue<int> q;
    q.push(1);
    while(not q.empty()) {
        int u = q.front(); q.pop();
        for(int v : G[u]) {
            if(minDistance[v] > minDistance[u] + 1) {
                minDistance[v] = minDistance[u] + 1;
                prevNode[v] = u;
                q.push(v);
            }
        }
    }
    if(minDistance[N] == INF) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> path;
        for(int u=N;u!=1;u=prevNode[u]) {
            path.push_back(u);
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        cout << path.size() << '\n';
        for(int u : path) {
            cout << u << ' ';
        }
        cout << '\n';
    }
    return 0;
}
