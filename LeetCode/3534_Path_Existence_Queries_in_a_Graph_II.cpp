class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        const int MAXN = 1e5 + 5;
        int tb[MAXN][19]; // tb[pos][pow] -> furthest point can go within 2**(pow-1) steps
        map<int, int> mp;
        fill(&tb[0][0], &tb[0][0]+MAXN*19, n);
        for(int i=0;i<n;++i) {
            mp.emplace(nums[i], i);
        }
        nums.push_back(-1);
        for(int u=0;u<n;++u) {
            tb[u][0] = u;
            if(auto result=mp.upper_bound(nums[u]+maxDiff); result!=mp.begin()) {
                tb[u][1] = prev(result)->second;
            } else {
                tb[u][1] = u;
            }
        }
        for(int i=2;i<19;++i) {
            for(int u=0;u<n;++u) {
                if(nums[tb[u][i]] < nums[tb[tb[u][i-1]][i-1]])
                    tb[u][i] = tb[tb[u][i-1]][i-1];
            }
        }
        vector<int> output;
        for(auto query: queries) {
            int a = query[0], b = query[1];
            if(nums[a] == nums[b]) {
                if(a == b)
                    output.push_back(0);
                else
                    output.push_back(1);
                continue;
            }

            if(nums[b] < nums[a]) swap(a, b);
            if(nums[tb[a][18]] < nums[b]) {
                output.push_back(-1);
                continue;
            }
            int ans = 0;
            for(int i=18;i>=1;i--) {
                if(nums[tb[a][i]]<nums[b]) {
                    ans += (1 << (i-1));
                    a = tb[a][i];
                }
            }

            output.push_back(ans+1);
        }
        return output;
    }
};
