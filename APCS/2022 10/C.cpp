#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<int> > vvi;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second


queue<int> Que;
uint64_t ans = 0;
void solve() {
    int u = Que.front(); Que.pop();
    int cnt = 2 + (u%2);
    for(int i=0;i<cnt;++i) {
        int v = Que.front();
        if(v!=0) {
            ans += abs(u-v);
            solve();
        } else {
            Que.pop();
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r;
    while(cin >> r) {
        Que.push(r);
    }
    solve();
    cout << ans << '\n';
    return 0;
}