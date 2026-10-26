class Solution {
public:
    long long dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= (int)grid.size() || j >= (int)grid[0].size() || grid[i][j] == 0) {
            return 0;
        }
        long long sum = grid[i][j];
        grid[i][j] = 0;
        sum += dfs(grid, i+1, j);
        sum += dfs(grid, i-1, j);
        sum += dfs(grid, i, j+1);
        sum += dfs(grid, i, j-1);
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] != 0) {
                    long long total = dfs(grid, i, j);
                    if (total % k == 0) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};