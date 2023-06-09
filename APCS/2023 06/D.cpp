#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M, K, T;
    cin >> N >> M >> K >> T;
    vector<int> Tr;
    for(int i=0;i<T;++i) {
        int a;
        cin >> a;
        Tr.push_back(a);
    }
    vector<int> in(N), op[M], to[N];
    for(int i=0;i<N;++i) {
        for(int j=0;j<K;++j) {
            int a;
            cin >> a;
            op[a].push_back(i);
            in[i]++;
        }
    }
    for(int i=0;i<N;++i) {
        for(int j=0;j<K;++j) {
            int a;
            cin >> a;
            to[i].push_back(a);
        }
    }
    queue<int> Q;
    int64_t ans = 0;
    vector<bool> visited(M);
    for(int key: Tr) {
        visited[key] = true;
        for(int box: op[key]) {
            in[box]--;
        }
    }
    for(int i=0;i<N;++i) {
        if(in[i] == 0) {
            Q.push(i);
        }
    }
    while(!Q.empty()) {
        int tmp = Q.front(); Q.pop();
        ans++;
        for(int &key: to[tmp]) {
            if(visited[key])
                continue;
            for(int &box: op[key]) {
                in[box]--;
                if(in[box] == 0) {
                    Q.push(box);
                }
            }
            visited[key] = true;
        }
    }
    cout << ans << '\n';
    return 0;
}
