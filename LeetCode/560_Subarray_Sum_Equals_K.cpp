class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int64_t, int> mp = {{0, 1}};
        int pre_sum = 0;
        int ans = 0;
        for(const auto &num: nums) {
            pre_sum += num;
            if(mp.contains(pre_sum - k)) {
                ans += mp[pre_sum - k];
            }
            mp[pre_sum] += 1;
        }
        return ans;
    }
};
