class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        vector<int> f(nums.size());
        int ans = 0;
        for(int i = 2; i < nums.size(); ++i){
            if(nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
                f[i] = f[i - 1] + 1;
            else
                f[i] = 0;
            ans += f[i];
        }
        return ans;
    }
};