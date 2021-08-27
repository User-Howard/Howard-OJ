#include <iostream>
#include <vector>
using namespace std;


uint64_t solve(){
    uint32_t N, K;
    cin >> N >> K;
    N ++;
    if(N > 1000000)
        return 98765432123456789;
    vector<uint64_t> dp(N);
    vector<uint64_t> su(N);
    dp [0] = 1;
    su [0] = 1;
    for (int i = 1;i < N;++i) {
        if (dp [i-1] > 98765432123456789) {
            return 98765432123456789;
        }
        dp [i] = dp [i - 1] + su [i - 1] - (i-1 >= K ? dp [i - K - 1] : 0);
        su [i] = dp [i] + su [i - 1] - (i-1 >= K ? dp [i - K - 1] : 0);
    }
    if (dp [N - 1] >= 98765432123456789) {
        return 98765432123456789;
    }
    else
        return dp[N-1];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        cout << solve() << '\n';
    }
    
    return 0;
}