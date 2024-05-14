#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> pii;

int N;
int Nums[5005];
int64_t prefix[5005];
int64_t dp[5005][5005];
int main() {
    cin >> N;
    for(int i=1;i<=N;++i) {
        cin >> Nums[i];
        prefix[i] = prefix[i-1] + Nums[i];
    }
    for(int i=1;i<=N;++i)
        dp[i][i] = Nums[i];
    for(int i=1;i<N;++i) {
        for(int j=1;j+i<=N;++j) {
            dp[j][j+i] = max(prefix[j+i]-prefix[j-1]-dp[j+1][j+i] ,\
                             prefix[j+i]-prefix[j-1]-dp[j][j+i-1]);
        }
    }
    cout << dp[1][N] << '\n';

    return 0;
}
