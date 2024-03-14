#include <iostream>
#include <vector>
using namespace std;


int main() {
    int N, M;
    while(cin >> N >> M and not (!N and !M)) {
        vector<uint64_t> dp(M+1);
        dp[0] = 1;
        for(int i=0;i<N;++i) {
            for(int j=M;j>=1;--j) {
                dp[j] = dp[j] + dp[j-1];
            }
        }
        cout << N << " things taken " << M << " at a time is " << dp[M] << " exactly.\n";
    }
    return 0;
}