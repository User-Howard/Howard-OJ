#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int64_t INF = 1LL<<62;
const int MAX_N = 2505;
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> U(M), V(M), W(M);
    for(int i=0;i<M;++i) {
        cin >> U[i] >> V[i] >> W[i];
        U[i]--; V[i]--;
    }
    vector<int64_t> dis(N, INF);
    vector<int> path(N);
    dis[0] = 0;
    int tag;
    for(int t=1;t<=N;++t) {
        tag = -1;
        for(int i=0;i<M;++i) {
            if(dis[V[i]] > dis[U[i]] + W[i]) {
                dis[V[i]] = dis[U[i]] + W[i];
                path[V[i]] = U[i];
                tag = V[i];
            }
        }

    }
    if (tag != -1) {
        cout << "YES" << '\n';
        vector<int> ans;
        for (int i = 0; i < N; ++i)
            tag = path[tag];
        int pointer = tag;
        do {
            ans.push_back(pointer);
            pointer = path[pointer];
        } while (pointer != tag);
        ans.push_back(tag);
        for (int i = ans.size() - 1; i >= 0; --i) {
            cout << ans[i] + 1 << ' ';
        }
        cout << '\n';
    }
    else {
        cout << "NO" << '\n';
    }
    return 0;
}
