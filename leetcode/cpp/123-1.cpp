class Solution {
public:
    // Dynamic Programming
    // Thanks to https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/2550543/c%2B%2B-oror-DP-oror-Recursion-oror-Iteration-oror-O(n*2*3)-time-complexity
    int solve(vector<vector<vector<int>>> & dp, vector<int>& prices, int ind, int buy, int cap, int n){
        if(ind >= n || cap < 1) return 0;
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        
        if(!buy){
            dp[ind][buy][cap] = max(- prices[ind] + solve(dp, prices, ind + 1, 1, cap, n), solve(dp, prices, ind + 1, 0, cap, n));
        }else{
            dp[ind][buy][cap] = max(prices[ind] + solve(dp, prices, ind + 1, 0, cap - 1, n) , solve(dp, prices, ind + 1, 1, cap, n));
        }
        return dp[ind][buy][cap];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(dp, prices, 0, 0, 2, n);
    }
};