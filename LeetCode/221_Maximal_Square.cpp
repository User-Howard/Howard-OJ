class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int dp[n+1][m+1];
        int ans = 0;
        for(int i=0;i<=n;++i) dp[i][0] = 0;
        for(int i=0;i<=m;++i) dp[0][i] = 0;
        for(int i=1;i<=n;++i) {
            for(int j=1;j<=m;++j) {
                if(matrix[i-1][j-1]=='0') {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = 1;
                int mn = min(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = mn + bool(dp[i-mn][j-mn]>0);
                ans = max(dp[i][j], ans);
            }
        }
        return ans*ans;
    }
};
