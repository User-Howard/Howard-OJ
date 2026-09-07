class Solution {
public:
    int distinctSubseqII(string s) {
        const int n = s.size();
        const int mod = 1e9 + 7;
        vector<int64_t> dp(n+1);
        vector<int> last(26, -1);
        dp[0] = 1;
        for(int i=0;i<n;++i) {
            int ch = s[i] - 'a';
            dp[i+1] = 2 * dp[i] % mod;
            if(~last[ch]) {
                dp[i+1] -= dp[last[ch]];
            }
            dp[i+1] = dp[i+1] % mod;
            last[ch] = i;
        }
        int64_t ans = ((1LL*dp[n]-1) % mod + mod) % mod;
        return ans;
    }
};
