class Solution {
public:
    int numSquares(int n) {
        int s = sqrt(n);
        vector<int> nums;
        for(int i = 1; i <= s; ++i)
            nums.push_back(i * i);
        vector<int> dp(n + 10, INT_MAX);
        dp[0] = 0;
        for(int s : nums){
            for(int j = s; j <= n; ++j)
                dp[j] = min(dp[j], dp[j - s] + 1);
        }
        return dp[n];
    }
};