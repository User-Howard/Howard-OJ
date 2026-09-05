using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
    vi buf{};
    vvi ans;
    int buf_sum{};
    vi candidates;
    int target;
    void dfs(int pos) {
        if(buf_sum==target) {
            ans.push_back(buf);
            return;
        }
        if(buf_sum>target or pos>=candidates.size()) return;
        
        int next_pos=pos;
        while(next_pos<candidates.size() and candidates[pos]==candidates[next_pos]) next_pos++;
        
        // add candidates[pos] and move to next position which is not the same
        dfs(next_pos);
        for(int i=pos;i<next_pos;++i) {
            buf.push_back(candidates[pos]);
            buf_sum+=candidates[pos];
            dfs(next_pos);
        }
        for(int i=pos;i<next_pos;++i) {
            buf.pop_back();
            buf_sum-=candidates[pos];
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        this->target = target;
        dfs(0);
        return ans;
    }
};

