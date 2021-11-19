class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1, n = nums.size();
        vector<int> dp(n, 1);
        for(int i = 1; i < n; ++i){
            int k = 0;
            for(int j = 0; j < i; ++j)
                if(nums[j] < nums[i] && dp[j] > k)
                    k = dp[j];
            dp[i] = k + 1;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};