#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


const int INF = 0x3f3f3f3f;
const int maxn = 1e3 + 5;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(auto &i: A) cin >> i;
    vector<int> prefix_sum(N+1);
    for(int i=0;i<N;++i) {
        prefix_sum[i+1] = prefix_sum[i] + A[i];
    }

    int dp[maxn][maxn];
    fill(&dp[0][0], &dp[0][0]+maxn*maxn, INF);
    for(int i=0;i<N;++i) dp[i][i] = 0;
    for(int len=1; len<N; ++len) {
        for(int l=0, r=len; r<N; ++l, ++r) {
            for(int k=l; k+1<=r; ++k) {
                int lsum = prefix_sum[k+1] - prefix_sum[l];
                int rsum = prefix_sum[r+1] - prefix_sum[k+1];
                dp[l][r] = min(dp[l][k]+dp[k+1][r] + abs(lsum - rsum) , dp[l][r]);
            }
        }
    }
    cout << dp[0][N-1] << '\n';
    return 0;
}
