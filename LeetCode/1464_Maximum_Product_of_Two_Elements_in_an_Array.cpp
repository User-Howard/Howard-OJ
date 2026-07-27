class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int n = size(nums);
        return (nums[n-1]-1)*(nums[n-2]-1);
    }
};
