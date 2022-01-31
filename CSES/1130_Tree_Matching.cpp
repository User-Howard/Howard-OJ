#include <iostream>
#include <vector>
using namespace std;


int N, ans = 0;
const int MAX_N = 2e5 + 5;
vector<int> G[(MAX_N)];
int mark[MAX_N];
void dfs(int x, int pre){
    for (auto i:G[x]){
        if (i == pre) continue;
        dfs(i, x);
        if (!mark[i] && !mark[x]){
            mark[i] = mark[x] = 1;
            ans++;
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int a, b;
    for(int i = 1;i < N;++i){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, 0);
    cout << ans << '\n';
    return 0;
}
// Finish time 25min
