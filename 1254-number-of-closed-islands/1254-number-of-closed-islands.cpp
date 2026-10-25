class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c) {
        int m = grid.size(), n = grid[0].size();
        if (r < 0 || c < 0 || r >= m || c >= n) return 0;
        if (grid[r][c] == 1) return 1;
        grid[r][c] = 1;
        int a = dfs(grid, r+1, c);
        int b = dfs(grid, r-1, c);
        int d = dfs(grid, r, c+1);
        int e = dfs(grid, r, c-1);
        return a && b && d && e;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    if (dfs(grid, i, j)) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};