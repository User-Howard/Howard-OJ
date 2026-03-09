class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_len = 200;
        for(auto &s: strs) min_len = min(s.length(), (size_t)min_len);
        int ans = 0;
        for(;ans<min_len;++ans) {
            bool flag = false;
            for(auto &s: strs) {
                if(s[ans]!=strs[0][ans]) {
                    flag = true;
                }
            }
            if(flag) break;
        }
        return strs[0].substr(0, ans);
    }
};
