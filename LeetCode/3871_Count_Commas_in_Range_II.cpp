class Solution {
public:
    long long countCommas(long long n) {
        vector<int64_t> tier = {1};
        while(tier.back()*1000 <= n) tier.emplace_back(tier.back()*1000);
        // 剛好小於n
        int64_t ans = (size(tier)-1)*(n-tier.back()+1);
        for(int i=0;i<size(tier)-1;++i) {
            ans += 999*i*tier[i];
        }
        return ans;
    }
};
//     1,000 ~     999,999
// 1,000,000 ~ 999,999,999
