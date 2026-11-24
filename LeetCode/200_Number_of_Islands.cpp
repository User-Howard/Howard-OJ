class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const int n = grid.size(), m = grid[0].size();

        auto dfs = [&](this auto&& dfs, int x, int y) -> void {
            if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] != '1') return;
            grid[x][y] = '0';
            dfs(x - 1, y); dfs(x + 1, y);
            dfs(x, y - 1); dfs(x, y + 1);
        };

        int count = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] == '1') { ++count; dfs(i, j); }
        return count;
    }
};
