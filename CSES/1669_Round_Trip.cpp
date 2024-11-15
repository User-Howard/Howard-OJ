#include <iostream>
#include <vector>
using namespace std;


const int MAX_N = 1e5 + 5;
int N, M;
vector<bool> visited(MAX_N, false);
vector<int> rec;
vector<int> G[MAX_N];
void solve(int x, int pre=-1, int t=0) {
    for(int v: G[x]) {
        if(v == pre) continue;
        if(!visited[v]) {
            rec.push_back(v);
            visited[v] = true;
            solve(v, x);
            rec.pop_back();
        } else {
            int pointer = rec.size()-1;
            vector<int> answer;
            do {
                answer.push_back(rec[pointer--]);
            }while(pointer >=0 and rec[pointer]!=v);
            cout << answer.size()+2 << '\n';
            cout << v << ' ';
            for(int i: answer) {
                cout << i << ' ';
            }
            cout << v << '\n';
            exit(0);
        }
    }
}
int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<M;++i) {
        static int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=1;i<=N;++i) {
        if(visited[i]) continue;
        visited[i] = true;
        rec.clear();
        rec.push_back(i);
        solve(i);
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
