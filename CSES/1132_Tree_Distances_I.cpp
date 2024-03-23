#include <iostream>
#include <vector>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;

const int MAX_N = 2e5 + 5;
int N;
vector<int> G[MAX_N];
void solve(vector<int>& vec, int x, int pre=-1, int cnt=0) {
    vec[x] = max(vec[x], cnt);
    for(int i: G[x]) {
        if(i == pre) continue;
        solve(vec, i, x, cnt+1);
    }
}
int main() {
    cin >> N;
    for(int i=2, a, b;i<=N;++i) {
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    vector<int> ans(N+1);
    int tail;
    for(int i=0;i<3;++i) { // 1. find edge; 2,3. find answer
        tail = distance(ans.begin(), max_element(next(ans.begin()), ans.end()));
        solve(ans, tail);
    }
    for(int i=1;i<=N;++i)
        cout << ans[i] << " \n"[i==N];
    
    return 0;
}
