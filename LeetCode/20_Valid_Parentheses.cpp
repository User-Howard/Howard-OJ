class Solution {
public:
    map<char, char> mp = {
        {'(', '('},
        {')', '('},
        {'[', '['},
        {']', '['},
        {'{', '{'},
        {'}', '{'},
    };
    bool isValid(string s) {
        if(s.empty()) return true;
        char fnt = s[0];
        if(fnt!=mp[fnt]) return false;
        char target = mp[fnt];
        int cnt = 0;
        for(int i=0;i<s.size();++i) {
            if(s[i] == target) {
                cnt++;
            } else if(mp[s[i]] == target) {
                cnt--;
            }
            if(cnt==0) {
                if(isValid(s.substr(1, i-1)) and (i+1>=s.size() or isValid(s.substr(i+1)))) return true;
                return false;
            }
        }
        return cnt==0;
    }
};
