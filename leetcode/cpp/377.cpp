class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 10, 0);
        dp[0] = 1;
        for(int i = 1; i <= target; ++i){
            dp[i] = 0;
            for(int j = 0; j < nums.size(); ++j){
               if(i - nums[j] >= 0)
                   dp[i] = dp[i] + dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};