class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {
        stack<array<int, 3> > st; // {type, color, cnt}
        for (int i = 0; i < (int)types.size(); ++i) {
            int t = types[i], c = colors[i];
            if (!st.empty() && st.top()[0] == t && st.top()[1] == c)
                st.top()[2]++;
            else
                st.push({t, c, 1});

            if (st.top()[2] == groupSize[t])
                st.pop();
        }
        return st.empty();
    }
};
