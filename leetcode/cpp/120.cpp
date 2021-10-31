class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        vector<int> dp(rows + 10, INT_MAX - 1000000);
        dp[0] = triangle[0][0];
        for(int i = 1; i < rows; ++i){
            for(int j = i; j >=0; --j){
                // cout<<i<<": "<<j<<endl;
                if(j > 0)
                    dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
                else
                    dp[j] = dp[j] + triangle[i][j];
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i < rows; ++i)
            ans = min(ans, dp[i]);
        return ans;
    }
};