class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int ans = 0;
        int lst = -1;
        for(int i=0;i<size(s);++i) {
            char c = s[i];
            if(c=='(') {
                st.push(i);
            } else {
                if(st.empty()) {
                    lst = i;
                    continue;
                }
                int lhs = st.top(); st.pop();
                if(st.empty()) {
                    ans = max(i-lst, ans);
                } else {
                    ans = max(i-st.top(), ans);
                }
            }
        }
        return ans;
    }
};
