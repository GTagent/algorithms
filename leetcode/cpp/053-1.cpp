class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> f(nums.size());
        int ans = nums[0];
        f[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            if (f[i-1] + nums[i] > nums[i])
                f[i] = f[i-1] + nums[i];
            else
                f[i] = nums[i];
            if (f[i] > ans)
                ans = f[i];
        }
        return ans;
    }
};