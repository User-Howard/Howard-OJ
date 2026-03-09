using vi = vector<int>;
using vvi = vector<vi>;
const int maxn = 2e5;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vvi result;
        const int N = nums.size();
        for(int i=0;i<N;++i) {
            if(i and nums[i-1]==nums[i]) continue;
            int l=i+1, r = N-1;
            while(r-l>0) {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum > 0) {
                    r--;
                } else if(sum < 0) {
                    l++;
                } else {
                    result.emplace_back(vi({nums[i], nums[l], nums[r]}));
                    r--;
                    while(r>i and nums[r] == nums[r+1]) r--;
                    l++;
                    while(l<N and nums[l-1] == nums[l]) l++;
                }
            }
        }
        return result;

    }
};
