#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int MAX_N = 2e5 + 5;
struct E {
    int sum;
    int cnt;
    E& operator+=(const E& rhs) {
        this->sum += rhs.sum;
        this->cnt += rhs.cnt;
        return *this;
    }
};
int N;
ll ans[MAX_N]={0};
ll child[MAX_N]={0};
vector<int> G[MAX_N];
void getChildCount(int u, int pre=-1) {
    for(int v: G[u]) {
        if(v==pre) continue;
        getChildCount(v, u);
        child[u] += child[v];
    }
    child[u]++;
}
void getSum(int u, int pre=-1) {
    for(int v: G[u]) {
        if(v==pre) continue;
        getSum(v, u);
        ans[u] += ans[v] + child[v];
    }
}
void solve(int u, int pre=-1) {
    for(int v: G[u]) {
        if(v==pre) continue;
        ans[v] = ans[u] + N - 2*child[v];
        solve(v, u);
    }
}
int main() {
    // freopen("in", "r", stdin);
    cin >> N;
    int cnt[MAX_N]={0};
    for(int i=0;i<N-1;++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
        cnt[a]++;
        cnt[b]++;
    }
    for(int i=1;i<=N;++i) {
        if(cnt[i]==1) {
            getChildCount(i);
            getSum(i);
            solve(i);
            break;
        }
    }
    for(int i=1;i<=N;++i) {
        cout << ans[i] << " ";
    }
    return 0;
}
