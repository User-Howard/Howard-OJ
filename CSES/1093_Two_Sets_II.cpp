#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


const int MAX_N = 500 + 5;
const int MAX_SUM = MAX_N*(MAX_N+1)/2 + 5;
const int MOD = 1e9 + 7;
int N;
int64_t dp[MAX_SUM+5];
int main() {
    cin >> N;
    fill(dp, dp+MAX_SUM, 0);
    dp[0] = 1;
    for(int i=1;i<=N;++i) {
        for(int j=MAX_SUM;j>=i;--j) {
            dp[j] += dp[j-i];
            dp[j] %= 2*MOD;
        }
    }
    if(N*(N+1)/2 % 2) {
        cout << 0 << '\n';
    }
    else {
        cout << dp[N*(N+1)/4]/2 << '\n';
    }
    return 0;
}
