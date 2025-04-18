#include "..\head.h"

int min_path_sum_dfs(vector<vector<int>> &grid, int i ,int j) {
    if (i == 0 && j == 0) {
        return grid[0][0];
    }
    if (i < 0 || j < 0) {
        return INT_MAX;
    }
    int up = min_path_sum_dfs(grid, i - 1, j);
    int left = min_path_sum_dfs(grid, i, j - 1);
    return min(left, up) != INT_MAX ? min(left, up) + grid[i][j] : INT_MAX;
}

int min_path_sum_dfs_mem(vector<vector<int>>& grid, vector<vector<int>> &mem, int i, int j) {
    // 若为左上角单元格，则终止搜索
    if (i == 0 && j == 0) {
        return grid[0][0];
    }
    // 若行列索引越界，则返回 +∞ 代价
    if (i < 0 || j < 0) {
        return INT_MAX;
    }
    if (mem[i][j] != -1) {
        return mem[i][j];
    }
    int up = min_path_sum_dfs_mem(grid, mem, i - 1, j);
    int left = min_path_sum_dfs_mem(grid, mem, i, j - 1);
    // 记录并返回左上角到 (i, j) 的最小路径代价
    mem[i][j] = min(left, up) != INT_MAX ? min(left, up) + grid[i][j] : INT_MAX;
    return mem[i][j];
}

int min_path_sum_dp(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = grid[0][0];
    for (int j = 1; j < m; j ++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    for (int i = 1; i < n; i ++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (int i = 1; i < n; i ++) {
        for (int j = 1; j < m; j ++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    return dp[n - 1][m - 1];
}

int min_path_sum_dp_cmp(vector<vector<int>> & grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<int> dp(m);
    dp[0] = grid[0][0];
    for (int j = 1; j < m; j ++) {
        dp[j] = dp[j - 1] + grid[0][j];
    }
    for (int i = 1; i < n; i ++) {
        dp[0] = dp[0] + grid[i][0];
        for (int j = 1; j < m; j ++) {
            dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
        }
    }
    return dp[m - 1];
}