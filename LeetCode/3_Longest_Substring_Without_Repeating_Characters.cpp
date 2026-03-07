class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, bool> mp;
        int ptr = -1;
        int ans = 0;
        for(int i=0;i<s.size();++i) {
            while(ptr+1 < s.size() and not mp[s[ptr+1]]) {
                mp[s[ptr+1]] = true;
                ptr++;
            }
            ans = max(ptr-i+1, ans);
            mp[s[i]] = false;
        }
        return ans;
    }
};
