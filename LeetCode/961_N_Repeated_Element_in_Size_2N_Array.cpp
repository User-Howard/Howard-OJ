class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> st;
        int ans=-1;
        for(auto &i: nums) {
            if(st.contains(i)) {
                ans = i;
                break;
            }
            st.insert(i);
        }
        return ans;
    }
};
