#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <sstream>
using namespace std;


const int max_n = 1e5 + 10;
vector<pair<int, int> > G[max_n];
int ans=0;
int dfs(int u, int prv) {
    int max_route=0;
    for(auto t: G[u]) {
        if(t.first == prv) continue;
        int route = dfs(t.first, u) + t.second;
        ans = max(max_route + route, ans);
        max_route = max(route, max_route);
    }
    return max_route;
}
void init() {
    for(auto &g: G) {
        g.clear();
    }
    ans = 0;
}
int main() {
    int u, v, d;
    string S;
    while(getline(cin, S)) {
        if(S=="") {
            dfs(1, -1);
            cout << ans << '\n';
            init();
        } else {
            stringstream ss(S);
            ss >> u >> v >> d;
            G[u].emplace_back(v, d);
            G[v].emplace_back(u, d);

        }
    }
    dfs(1, -1);
    cout << ans << '\n';


    return 0;
}