class Solution {
public:
    int trap(vector<int>& height) {
        const int N = height.size();
        vector<int> left_high(height), right_high(height);
        for(int i = 1; i < N; ++i) {
            left_high[i] = max(left_high[i], left_high[i-1]);
        }
        for(int i = N - 2; i >= 0; --i) {
            right_high[i] = max(right_high[i], right_high[i+1]);
        }
        int ans = 0;
        for(int i = 0; i < N; ++i) {
            ans += min(left_high[i], right_high[i]) - height[i];
        }
        return ans;
    }
};

