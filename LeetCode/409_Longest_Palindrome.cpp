class Solution {
    public:
        int longestPalindrome(string s) {
            map<char, int> mp;
            for(char c: s)
                mp[c] ++;
            int ans = 0;
            bool has_odd = false;
            for(auto i: mp) {
                if(i.second%2) {
                    has_odd = true;
                    ans += i.second-1;
                } else {
                    ans += i.second;
                }
            }
            return ans + has_odd;
        }
    };