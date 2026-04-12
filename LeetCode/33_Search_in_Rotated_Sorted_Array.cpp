class Solution {
public:
    int search(vector<int>& nums, int target) {
        int fst = nums.front();
        bool at_left = (fst <=target);
        int l=0, r=nums.size();
        while(r-l>1) {
            int mid = (r+l) / 2;
            if(at_left) {
                if(nums[mid] < fst or target<nums[mid]) {
                    r = mid;
                } else {
                    l = mid;
                }
            } else {
                if(nums[mid] > fst or nums[mid] < target) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
        }
        if(nums[l]==target) {
            return l;
        } else if(r < nums.size() and nums[r]==target) {
            return r;
        } else {
            return -1;
        }
    }
};

