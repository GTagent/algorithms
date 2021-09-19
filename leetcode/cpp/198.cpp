class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> f(nums.size() + 10);
        f[0] = 0;
        f[1] = nums[0];
        for(int  i = 1; i < nums.size(); ++i){
            f[i + 1] = max(f[i], f[i - 1] + nums[i]);
        }
        return f[nums.size()];
    }
};