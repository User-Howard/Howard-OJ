#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
typedef long long ll;

string S;
inline int to_int(char c) {
    return ('9' < c)  ? (c-'A'+10) : (c-'0');
}
ll solve() {
    const int N = S.size();
    vector<vector<ll> > dp(2, vector<ll>(N+2, 0));
    if(S[0]=='?') {
        for(int i=1;i<=N;++i)
            dp[0][i] = 1;
    }
    else {
        dp[0][to_int(S[0])] = 1;
    }
    for(int c=1;c<N;++c) {
        fill(next(dp[1].begin()), prev(dp[1].end()), 0);
        for(int i=1;i<=N;++i) {
            for(int j=1;j<=N;++j) {
                if(i-1<=j and j<=i+1) continue;
                dp[1][i] += dp[0][j];
            }
        }
        swap(dp[0], dp[1]);
        if(S[c] != '?') {
            for(int i=1;i<=N;++i) {
                if(i == to_int(S[c])) continue;
                dp[0][i] = 0;
            }
        }
    }
    return accumulate(dp[0].begin(), dp[0].end(), 0LL);
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    while(cin >> S) {
        cout << solve() << '\n';
    }
    return 0;
}