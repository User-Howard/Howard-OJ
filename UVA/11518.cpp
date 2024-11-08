#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, L;
vector<int> G[10005];
vector<bool> visited(10005, false);
int main() {
    int T;
    cin >> T;
    while(T--) {
        cin >> N >> M >> L;
        for(int i=0;i<=N;++i) {
            G[i].clear();
            visited[i] = false;
        }
        for(int i=0;i<M;++i) {
            static int a, b;
            cin >> a >> b;
            G[a].push_back(b);
        }
        queue<int> q;
        int answer = 0;
        for(int i(0);i<L;++i) {
            static int a;
            cin >> a;
            q.push(a);
            visited[a] = true;
            while(not q.empty()) {
                int cur = q.front(); q.pop();
                for(int nxt: G[cur]) {
                    if(visited[nxt]) continue;
                    q.push(nxt);
                    visited[nxt] = true;
                }
            }
        }

        cout << answer << '\n';
    }
    return 0;
}
