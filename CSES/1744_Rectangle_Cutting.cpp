#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 500+5;
const int INF = 1e8;
long long int dp[MAX_N][MAX_N];
int main() {
    int A, B;
    cin >> A >> B;
    for(int i=0;i<MAX_N;++i)
        for(int j=0;j<MAX_N;++j)
            dp[i][j] = INF;
    for(int i=0;i<MAX_N;++i)
        dp[i][i] = 0;
    for(int i=0;i<MAX_N;++i) {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    for(int i=1;i<=A;++i) {
        for(int j=1;j<=B;++j) {
            for(int k=1;k<i;++k) {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
            }
            for(int k=1;k<j;++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
            }
        }
    }
    cout << dp[A][B] << endl;
    return 0;
}
