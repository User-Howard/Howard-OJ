class Solution {
public:
    map<char, int> mp = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int romanToInt(string s) {
        const int N = s.length();

        int result = 0;
        for(int i=0;i<N;++i) {
            result += mp[s[i]];
        }
        for(int i=1;i<N;++i) {
            if(mp[s[i-1]] < mp[s[i]])
                result -= 2*mp[s[i-1]];
        }
        return result;
    }
};
