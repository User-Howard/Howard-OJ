#include <iostream>
#include <vector>
using namespace std;


const int MAX_N = 1e5 + 5;
int N, M;
vector<int> G[MAX_N];
vector<int> tag(MAX_N, 0);
bool fill_tag(int x, int t=1) {
    if(tag[x] == 0) {
        tag[x] = t;
        for(int u: G[x]) {
            if(!fill_tag(u, -t)) {
                return false;
            }
        }
        return true;
    } else {
        return tag[x] == t;
    }
}
int main() {
    cin >> N >> M;
    for(int i=0;i<M;++i) {
        static int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=1;i<=N;++i) {
        if(tag[i] != 0) continue;
        if(!fill_tag(i)) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    for(int i=1;i<=N;++i) {
        cout << (tag[i]==1 ? 1 : 2) << " ";
    }
    return 0;
}
