#include <iostream>
#include <array>
#include <utility>
using namespace std;
#define ifnot(x) if(x)
#define f first
#define s second
typedef pair<int, int> pii;

int N, K;
const int MaxSize = 20;
const int biMaxSize = 1<<20;
array<pii, biMaxSize> dp;
array<int, 20> Nums;
int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    cin >> N >> K;
    for(int i=0;i<N;i++) {
        cin >> Nums[i];
    }

    dp[0] = {1, 0};
    for(int i=1;i<(1<<N);++i) {
        dp[i] = {21, -1};
        for(int d=0;d<N;d++) {
            if(not(i&(1<<d))) continue;
            pii &t = dp[i&~(1<<d)];
            pii tmp;
            if(t.s+Nums[d]>K) {
                tmp = {t.f+1, min(t.s, Nums[d])};
            } else {
                tmp = {t.f, t.s+Nums[d]};
            }
            dp[i] = min(dp[i], tmp);
        }
    }
    cout << dp[(1<<N)-1].f << '\n';
    return 0;
}
