class Solution {
    const int maxn = 1e3 + 5;
public:
    string longestPalindrome(string s) {
        bool dp[maxn][maxn];
        fill(&dp[0][0], &dp[0][0]+maxn*maxn, false);
        for(int i=0;i<s.length();++i) {
            dp[i][i] = true;
        }
        int st(0), le(0);
        for(int i=1;i<s.length();++i) {
            for(int j=0;j<s.length()-i;++j) {
                if(s[j]!=s[j+i])
                    continue;
                if(i==1 or dp[j+1][j+i-1]) {
                    dp[j][j+i] = true;
                    st = j;
                    le = i;
                }
            }
        }
        return s.substr(st, le+1);
    }
};
