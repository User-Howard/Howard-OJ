class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        const int n = nums.size();
        int ans=-1;
        vector<int> premax(n);
        vector<int> sufmin(n);
        premax[0] = nums[0];
        sufmin[n-1] = nums[n-1];
        for(int i=1;i<nums.size();++i) {
            premax[i] = max(nums[i], premax[i-1]);
            sufmin[n-1-i] = min(nums[n-1-i], sufmin[n-i]);
        }
        for(int i=0;i<nums.size();++i) {
            int lhs = premax[i];
            int rhs = sufmin[i];
            if(lhs-rhs<=k) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
