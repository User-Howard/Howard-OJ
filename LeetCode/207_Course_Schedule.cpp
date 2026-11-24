class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > G(numCourses);
        vector<int> ind(numCourses);
        for(const auto &v: prerequisites) {
            int a = v[0];
            int b = v[1];
            G[b].emplace_back(a);
            ind[a]++;
        }
        queue<int> que;
        for(int i=0;i<numCourses;++i) {
            if(ind[i] == 0) {
                que.push(i);
            }
        }
        int cnt = numCourses;
        while(not que.empty()) {
            int u = que.front(); que.pop();
            cnt--;
            for(int v: G[u]) {
                ind[v]--;
                if(ind[v] == 0) {
                    que.push(v);
                }
            }
        }
        return cnt == 0;
    }
};
