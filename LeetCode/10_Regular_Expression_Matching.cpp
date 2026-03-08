using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
    vvi memo;
    string s, p;
    bool dp(int i, int j) {
        if(memo[i][j]!=-1) return memo[i][j];

        bool ans;
        if (j==p.size()) {
            ans = (i == s.size());
        } else {
            bool first_match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

            if (j+1<p.size() && p[j+1]=='*') {
                ans = dp(i, j + 2) || (first_match && dp(i + 1, j));
            } else {
                ans = first_match && dp(i + 1, j + 1);
            }
        }
        return memo[i][j] = ans;
    }
    bool isMatch(string _s, string _p) {
        s = _s;
        p = _p;
        memo = vvi(s.length()+2, vi(p.length()+2, -1));
        return dp(0, 0);
    }
};
