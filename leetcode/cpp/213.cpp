class Solution {
public:
    int HouseRob(vector<int>& nums) {
        vector<int> f(nums.size() + 10);
        f[0] = 0;
        f[1] = nums[0];
        for(int  i = 1; i < nums.size(); ++i){
            f[i + 1] = max(f[i], f[i - 1] + nums[i]);
        }
        return f[nums.size()];
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> v1(nums.begin(), nums.end() - 1);
        vector<int> v2(nums.begin() + 1, nums.end());
        return max(HouseRob(v1), HouseRob(v2));
    }
};