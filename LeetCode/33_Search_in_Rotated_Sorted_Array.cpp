class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot = 0;
        for(int step = bit_floor(size(nums)); step; step >>= 1) {
            if(pivot+step < ssize(nums) and nums[0] < nums[pivot+step])
                pivot += step;
        }
        span<int> view(nums);
        vector<int>::iterator search_begin, search_end;
        auto range = (nums[0]<=target) ? view.first(pivot + 1) : view.subspan(pivot + 1);
        auto result = std::ranges::lower_bound(range, target);
        if(result == range.end() or *result!=target) {
            return -1;
        }
        return result - view.begin();
    }
};
