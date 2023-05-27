#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int M, N;
    cin >> M >> N;
    vector<vector<int> > dp(M+1, vector<int>(N+2, 0)), nums(M+1, vector<int>(N+2, 0));
    vector<int> l(N+2), r(N+2);
    for(int i=1;i<=M;++i) {
        for(int j=1;j<=N;++j)
            cin >> nums[i][j];
    }
    for(int i=1;i<=M;++i) {
        for(int j=1;j<=N;++j)
            l[j] = max(l[j-1], dp[i-1][j]) + nums[i][j];
        for(int j=N;j>=1;--j)
            r[j] = max(r[j+1], dp[i-1][j]) + nums[i][j];
        for(int j=1;j<=N;++j) {
            dp[i][j] = max(l[j], r[j]);
        }
    }
    cout << *max_element(dp[M].begin(), dp[M].end()) << '\n';
    return 0;
}