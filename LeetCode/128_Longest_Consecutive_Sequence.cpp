class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(const auto &num: nums) {
            st.insert(num);
        }
        unordered_set<int> to_remove;
        for(const auto &num: nums) {
            if(st.contains(num-1)) {
                to_remove.insert(num);
            }
        }
        unordered_set<int> unst;
        for(auto const &num: nums) {
            if(not to_remove.contains(num)) {
                unst.insert(num);
            }
        }
        int ans = 0;
        for(auto const &num: unst) {
            if(ans and not st.contains(num+ans-1)) continue;
            int cnt = 1;
            while(st.contains(num+cnt)) {
                cnt ++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
