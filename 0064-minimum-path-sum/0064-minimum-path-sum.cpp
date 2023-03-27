class Solution {
public:
 int minPathSum(vector<vector<int>>& grid) {
 int m = grid.size(), n = grid[0].size();
 if (m == 0 || n == 0) return 0;
 const int INF = 1e9 + 5;
 vector<vector<int>> dp(m, vector<int>(n, INF));
 dp[0][0] = grid[0][0];
 // dp[i][j]: the minimum sum from grid[0][0] to grid[i][j]
 // dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]
 for (int i = 0; i < m; ++i) {
 for (int j = 0; j < n; ++j) {
 if (i - 1 >= 0) dp[i][j] = min(grid[i][j] + dp[i - 1][j], dp[i][j]);
 if (j - 1 >= 0) dp[i][j] = min(grid[i][j] + dp[i][j - 1], dp[i][j]);
 }
 }
 return dp[m - 1][n - 1];
 }
};