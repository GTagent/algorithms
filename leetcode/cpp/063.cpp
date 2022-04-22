class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][1] = 1;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(!grid[i][j]){
                    dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j];
                }
            }
        }
        return dp[m][n];
    }
};