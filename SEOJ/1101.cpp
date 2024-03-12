#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


const int MAX_N = 1e5 + 5;
int N;
int tag[MAX_N];
vector<int> G[MAX_N];
void init() {
    fill(tag, tag+N, 0);
    for(int i=0;i<N;++i) G[i].clear();
}
bool walk(int x, int t=1) {
    // cout << "walk\t" << x << ' ' << t << '\n';
    if(tag[x] == -t) return false;
    if(tag[x] == t) return true;
    tag[x] = t;
    for(int i: G[x]) {
        if(!walk(i, -t))
            return false;
    }
    return true;
}
bool solve() {
    int M;
    cin >> N;
    cin >> M;
    init();
    for(int i=0, x, y;i<M;++i) {
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=0;i<N;++i) {
        if(tag[i]==0) {
            if(!walk(i)) return false;
        }
    }
    return true;
}
int main() {
    int T;
    cin >> T;
    while(T--) {
        if(solve()) cout << "NORMAL.\n";
        else cout << "RAINBOW.\n";
    }
    return 0;
}