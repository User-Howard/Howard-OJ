class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int64_t> pre_sum(n+1, 0);
        for(int i=1;i<=n;++i) {
            pre_sum[i] = pre_sum[i-1] + nums[i-1];
        }
        int ans = 0;
        for(int i=0;i<n;++i) {
            for(int j=i;j<n;++j) {
                if(pre_sum[j+1]-pre_sum[i] == k) {
                    ans += 1;
                }
            }
        }
        return ans;
    }
};
