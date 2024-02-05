#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MOD = 1e9+7;
int main() {
    int N, X;
    cin >> N >> X;
    vector<int> C(N);
    vector<uint64_t> dp(X+1);
    dp[0] = 1;
    for(int &i: C) cin >> i;
    for(int i=0;i<N;++i) {
        for(int j=0;j<=X;++j) {
            if(j<C[i]) continue;
            dp[j] += dp[j-C[i]];
            dp[j] %= MOD;
        }
    }
    cout << dp[X] << '\n';

    return 0;
}