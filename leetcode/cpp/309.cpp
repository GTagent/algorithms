class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(3));
        // dp[i][0] is noStockstate
        // dp[i][1] is inStockState
        // dp[i][2] is sellStockState
        dp[0][0] = 0;
        dp[0][1] = - prices[0];
        dp[0][2] = 0;
        for(int i = 1; i < prices.size(); ++i){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
        }
        return max(dp[prices.size() - 1][0], dp[prices.size() - 1][2]);
    }
};