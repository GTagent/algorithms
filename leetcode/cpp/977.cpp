class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> list(nums.size());
        int l = 0, r = nums.size() - 1;
        for(int k = nums.size() - 1; k >= 0; --k){
            if(abs(nums[l]) > abs(nums[r]))
                list[k] = abs(nums[l]) * abs(nums[l++]);
            else
                list[k] = abs(nums[r]) * abs(nums[r--]);
        }
        return list;
    }
};