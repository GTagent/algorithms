class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m + 2, vector<int>(n + 2, 0));
        int ans = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] == '1'){
                    // cout<<i<<" "<<j<<": ";
                    int k = min(dp[i][j + 1], dp[i + 1][j]);
                    // cout<<k<<" ";
                    if(matrix[i - k][j - k] == '1')
                        dp[i + 1][j + 1] = k + 1;
                    else
                        dp[i + 1][j + 1] = k;
                    // cout<<dp[i + 1][j + 1]<<"--"<<dp[i][j + 1]<<" "<<dp[i + 1][j]<<endl;
                    ans = max(ans, dp[i + 1][j + 1]);
                }
            }
        }
        return ans * ans;
    }
};