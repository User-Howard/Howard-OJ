#include <iostream>
using namespace std;

const int MAX_N = 1e5+2;
const int MAX_M = 100;
int Nums[MAX_N];
long long int dp[MAX_N][MAX_M];
const int MOD = 1e9+7;
int main() {
    int N, M;
    cin >> N >> M;
    for(int i=0;i<N;++i) {
        cin >> Nums[i];
    }
    if(Nums[0]) {
        dp[0][Nums[0]] = 1;
    } else {
        for(int i=1;i<=M;++i)
            dp[0][i] = 1;
    }
    for(int i=1;i<N;++i) {
        for(int j=1;j<=M;++j) {
            dp[i][j] = dp[i-1][j];
            if(j>1) dp[i][j] = dp[i][j] + dp[i-1][j-1];
            if(j<M) dp[i][j] = dp[i][j] + dp[i-1][j+1];
            dp[i][j] %= MOD;
        }
        if(Nums[i]) {
            for(int j=1;j<=M;++j) {
                if(j==Nums[i]) continue;
                dp[i][j] = 0;
            }
        }
    }
    uint64_t answer = 0;
    for(int i=1;i<=M;++i) {
        answer = (answer + dp[N-1][i]) % MOD;
    }
    cout << answer << '\n';
    return 0;
}
