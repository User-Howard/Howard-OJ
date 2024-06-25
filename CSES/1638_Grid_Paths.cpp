#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9+7;
int N;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<int64_t> dp(N+1, 0);
    vector<string> S(N);
    for(string &i: S)
         cin >> i;
    dp[0] = 1;
    for(string s: S) {
        for(int i=1;i<=N;++i) {
            dp[i] += dp[i-1];
            dp[i] %= MOD;
            if(s[i-1]=='*') dp[i] = 0;
        }
        dp[0] = 0;
    }

    cout << dp[N] << '\n';
    return 0;
}
