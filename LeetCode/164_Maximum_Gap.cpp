class Solution {
    public:
        int maximumGap(vector<int>& nums) {
            if(size(nums)==1) return 0;
            
            vector<int> boxs(size(nums));
            int value_range = *ranges::max_element(nums) - *ranges::min_element(nums);
            int gap = max<size_t>(1, value_range / (size(nums)-1));
            int min_val = *ranges::min_element(nums);
            int box_count = value_range / gap + 1;
    
            vector<int> mi(box_count, 1e9), mx(box_count, -1e9);
            vector<bool> visit(box_count);
            for(int i: nums) {
                int t = (i-min_val) / gap;
                mi[t] = min(mi[t], i);
                mx[t] = max(mx[t], i);
                visit[t] = true;
            }
            int current_max_val = mx[0];
            int ans = mx[0] - mi[0];
            for(int i=1;i<box_count;++i) {
                if(not visit[i]) continue;
                ans = max(ans, mi[i]-current_max_val);
                current_max_val = mx[i];
            }
            return ans;
        }
    };