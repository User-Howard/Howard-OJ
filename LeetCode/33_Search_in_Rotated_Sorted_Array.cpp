class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ptr = 0;
        int step = bit_floor(size(nums));
        while(step) {
            if(ptr+step < ssize(nums) and nums[0] < nums[ptr+step])
                ptr += step;
            step >>= 1;
        }
        vector<int>::iterator search_begin, search_end;
        if(nums[0]<=target) {
            search_begin = nums.begin();
            search_end = next(nums.begin(), ptr+1);
        } else {
            search_begin = next(nums.begin(), ptr+1);
            search_end = nums.end();
        }
        if(auto result = lower_bound(search_begin, search_end, target); result != search_end and *result==target) {
            return distance(nums.begin(), result);
        } else {
            return -1;
        }
    }
};
