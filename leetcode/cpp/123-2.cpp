class Solution {
public:
    // DP iterative version
    // Thanks to https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/2550543/c%2B%2B-oror-DP-oror-Recursion-oror-Iteration-oror-O(n*2*3)-time-complexity
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for(int i = n - 1; i >= 0; --i){
            for(int k = 1; k <= 2; ++k){
                dp[i][0][k] = max(-prices[i] + dp[i + 1][1][k], dp[i + 1][0][k]);
                dp[i][1][k] = max(prices[i] + dp[i + 1][0][k - 1], dp[i + 1][1][k]);
            }
        }
        return dp[0][0][2];
    }
};