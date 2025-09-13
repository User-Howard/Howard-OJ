class Solution {
public:
    void quicksort(vector<int>& Nums, int l, int r) {
        if(r-l<=1) return;
        swap(Nums[rand()%(l-r)+l], Nums[l]);
        int last_smaller=l;
        for(int i=l+1;i<r;++i) {
            if(Nums[i] < Nums[l]) {
                swap(Nums[++last_smaller], Nums[i]);
            }
        }
        swap(Nums[last_smaller], Nums[l]);
        quicksort(Nums, l, last_smaller);
        quicksort(Nums, last_smaller+1, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, size(nums));
        return nums;
    }
};
