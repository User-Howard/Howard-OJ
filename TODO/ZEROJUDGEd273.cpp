#include <iostream>
#include <vector>
using namespace std;


const int INF = 0x3f3f3f3f;
bool is_palindrome(string& S, int x, int y) {
    int N = y - x + 1;
    for(int i=0;i<N/2;++i) {
        if(S[x+i] != S[x+N-i-1])
            return false;
    }
    return true;
}
int solve() {
    string S;
    cin >> S;
    const int N = S.size();
    vector<int> dp(N, INF);
    for(int i=0;i<N;++i) {
        if(is_palindrome(S, 0, i)) {
            dp[i] = 1;
        }
        for(int j=1;j<=i;++j) {
            if(is_palindrome(S, j, i))
                dp[i] = min(dp[i], dp[j-1]+1);
        }
    }
    return dp[N-1];
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        cout << solve() << '\n';
    }
    return 0;
}