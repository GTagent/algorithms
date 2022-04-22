class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m + 2, vector<int>(n + 2, INT_MAX));
        for(int i = 0; i < n; ++i){
            dp[1][i + 1] = matrix[0][i];
        }
        for(int i = 1; i < m; ++i){
            for(int j = 0; j < n; ++j){
                dp[i + 1][j + 1] = min(dp[i][j], min(dp[i][j + 1], dp[i][j + 2])) + matrix[i][j];
            }
        }
        int ans = INT_MAX;
        for(int i = 1; i <= n ; ++i){
            ans = min(ans, dp[m][i]);
        }
        return ans;
    }
};