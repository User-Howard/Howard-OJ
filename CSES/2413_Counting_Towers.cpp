#include <iostream>
using namespace std;


const int MOD = 1e9+7;
int main() {
    uint64_t dp[1000001][2];
    dp[1][0] = 1;
    dp[1][1] = 1;   
    for(int i=2;i<1000001;i++){
        dp[i][0] = dp[i-1][0]*2 + dp[i-1][1];
        dp[i][1] = dp[i-1][0] + dp[i-1][1]*4;

        dp[i][0]%=MOD;
        dp[i][1]%=MOD;
    }
    int T;
    cin >> T;
    while(T--) {
        static int n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1])%MOD << '\n';
    }
    return 0;
}