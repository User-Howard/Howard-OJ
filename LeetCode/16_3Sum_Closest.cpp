using vi = vector<int>;
using vvi = vector<vi>;
const int maxn = 2e4;
const int inf = 1e9;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        const int N = nums.size();
        int ans = inf;
        for(int i=0;i<N;++i) {
            if(i and nums[i-1]==nums[i]) continue;
            int l=i+1, r = N-1;
            while(r-l>0) {
                int sum = nums[i] + nums[l] + nums[r];
                if(abs(ans-target) > abs(sum-target)) {
                    ans = sum;
                }
                if(sum > target) {
                    r--;
                } else if(sum < target) {
                    l++;
                } else {
                    r--;
                    while(r>i and nums[r] == nums[r+1]) r--;
                    l++;
                    while(l<N and nums[l-1] == nums[l]) l++;
                }
            }
        }
        return ans;

    }
};
