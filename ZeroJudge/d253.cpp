#include <iostream>
#include <algorithm>
using namespace std;


const int MAX_N = 7489;
uint64_t dp[MAX_N+1];
int main() {
    fill(dp, dp+MAX_N, 0);
    dp[0] = 1;
    for(int coin: {1, 5, 10, 25, 50}) {
        for(int i=coin;i<=MAX_N;++i) {
            dp[i] += dp[i-coin];
        }
    }
    int N;
    while(cin >> N) {
        cout << dp[N] << '\n';
    }
    return 0;
}
