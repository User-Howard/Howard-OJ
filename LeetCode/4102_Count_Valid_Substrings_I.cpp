class Solution {
public:
    long long countValidSubstrings(string s) {
        int64_t ls = -1;
        int64_t ans = 0;
        for(int i=0;i<s.size();++i) {
            if(i>=2 and s.substr(i-2, 3)=="abc") {
                ls = i-2;
            }
            ans += 1LL*(i - ls);
        }
        return ans;
    }
};
