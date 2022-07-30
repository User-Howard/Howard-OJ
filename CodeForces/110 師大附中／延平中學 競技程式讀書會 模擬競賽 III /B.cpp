#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;


const uint64_t INF = 1e19;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> T(N), S(N);
    for(int i=0;i<N;++i)
        cin >> T[i] >> S[i];
    uint64_t sum = accumulate(S.begin(), S.end(), 0);
    vector<uint64_t> dp(sum+1, INF);
    dp[0] = 0;
    for(int i=0;i<N;++i) {
        for(int j=sum;j>=0;--j) {
            if(j - S[i] >= 0)
                dp[j] = min(dp[j - S[i]] + T[i], dp[j]);
        }
    }
    cout << *min_element(dp.begin()+M, dp.end()) << '\n';
    return 0;
}