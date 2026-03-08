class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int ans = 0;
        while(r-l > 0) {
            int threshold = min(height[l], height[r]);
            int distance = r - l;
            ans = max(ans, threshold*distance);
            if(r-l>0 and height[l]==threshold)
                l++;
            if(r-l>0 and height[r]==threshold)
                r--;
        }
        return ans;
    }
};
