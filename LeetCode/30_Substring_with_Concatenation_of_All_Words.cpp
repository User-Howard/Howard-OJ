class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        const int n = words.size();
        const int ss = s.size();
        const int ws = words.front().length();
        const int total_len = n * words.front().length();
        map<string, int> standard_mp;
        map<string, int> mp;
        for(auto &word: words) standard_mp[word]++;
        
        vector<int> result;
        for(int offset=0;offset<ws;++offset) {
            for(auto [word, cnt]: standard_mp) mp[word] = cnt;
            int ptr=0;
            bool flag = false;
            for(int i=0;i<(ss-offset)/ws;++i) {
                auto curr = s.substr(offset+ws*i, ws);
                if(mp.find(curr)==mp.end()) {
                    if(flag)
                        for(auto [word, cnt]: standard_mp) mp[word] = cnt;
                    flag = false;
                    ptr=i+1;
                    continue;
                }
                while(ptr<(ss-offset)/ws) {
                    auto target = s.substr(offset+ws*ptr, ws);
                    if(mp.find(target)==mp.end() or mp[target]==0) {
                        break;
                    } else {
                        flag = true;
                        mp[target]--;
                        ptr++;
                    }
                }
                if(ptr-i==n) result.emplace_back(offset+i*ws);
                if(mp.find(curr)==mp.end()) continue;
                mp[curr]++;
            }
        }
        return result;
    }
};

