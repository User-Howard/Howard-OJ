class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for(const auto &num: st) {
            if(st.contains(num-1)) continue;
            int cnt = 1;
            while(st.contains(num+cnt)) cnt++;
            ans = max(ans, cnt);
        }
        return ans;
   }
}; 
