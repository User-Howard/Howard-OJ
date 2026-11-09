class Solution {
    const long long mod = 10000000000000000 + 3;
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int, 26>, vector<string> > mp;
        for(const auto &s: strs) {
            array<int, 26> arr = {0};
            for(const auto &c: s) arr[c-'a']++;
            mp[arr].push_back(s);
        }
        vector<vector<string> > ans;
        for(auto &[s, v]: mp) {
            ans.emplace_back(move(v));
        }
        return ans;
    }
};
