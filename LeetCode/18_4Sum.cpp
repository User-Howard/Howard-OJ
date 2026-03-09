using vi = vector<int>;
using vvi = vector<vi>;
const int maxn = 2e4;
const int inf = 1e9;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        const int N = nums.size();
        vvi result;

        int prev_i = -1;
        for(int i=0;i<N;++i) {
            if(prev_i!=-1 and nums[prev_i]==nums[i]) continue;
            prev_i = i;
            int prev_j=-1;
            for(int j=i+1;j<N;++j) {
                if(prev_j!=-1 and nums[prev_j]==nums[j]) continue;
                prev_j = j;

                int l=j+1, r = N-1;
                while(r-l>0) {
                    int64_t sum = 0LL + nums[i] + nums[j] + nums[l] + nums[r];
                    if(sum > target) {
                        r--;
                    } else if(sum < target) {
                        l++;
                    } else {
                        result.emplace_back(vi({nums[i], nums[j], nums[l], nums[r]}));
                        r--;
                        while(r>j and nums[r] == nums[r+1]) r--;
                        l++;
                        while(l<N and nums[l-1] == nums[l]) l++;
                    }
                }
            }
        }
        return result;

    }
};
