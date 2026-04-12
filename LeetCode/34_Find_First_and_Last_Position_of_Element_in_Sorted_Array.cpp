class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto [a, b] = equal_range(nums.begin(), nums.end(), target);
        int l = distance(nums.begin(), a);
        int r = distance(nums.begin(), b)-1;
        cout << l << r ;
        if(r-l<0) {
            r = l = -1;
        }
        return vector<int>{l, r};
    }
};

