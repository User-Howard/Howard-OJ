#include <iostream>
using namespace std;


const int MAX_N = 1e5+2;
const int MOD = 1e9 + 7;
int N;
unsigned int dp[MAX_N][2] = {0};
int main(){
    cin >> N;
    dp[0][0] = dp[1][0] = dp[1][1] = 1, dp[2][0] = dp[2][1] = 2;
    for(int i=3;i<=N;++i){
        dp[i][0] = (dp[i-1][0]%MOD + dp[i-2][0]%MOD + dp[i-2][1]*2%MOD)%MOD;
        dp[i][1] = (dp[i-1][0]%MOD + dp[i-1][1]%MOD)%MOD;
    }
    cout << dp[N][0] << '\n';
    return 0;
}