using pii = pair<int, int>;
const int inf = 1e9;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int n = temperatures.size();
        vector<pii> st;
        vector<int> ans(n);
        for(int i=n-1;i>=0;--i) {
            while(not st.empty() and st.back().first <= temperatures[i]) {
                st.pop_back();
            }
            if(st.empty()) {
                ans[i] = 0;
            } else {
                ans[i] = st.back().second - i;
            }
            st.emplace_back(temperatures[i], i);
        }
        return ans;
    }
};
