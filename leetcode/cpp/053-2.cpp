class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return DnC(nums, 0, nums.size() - 1);
    }
    int DnC(vector<int> & nums, int l, int r){
        if(l > r){
            return -1000000;
        }
        int m = (l + r) >> 1, ml = 0, mr = 0;
        int lmax = DnC(nums, l, m - 1);
        int rmax = DnC(nums, m + 1, r);
        for(int i = m - 1, sum = 0; i >= 0; --i){
            sum += nums[i];
            ml = max(sum, ml);
        }
        for(int i = m + 1, sum = 0; i < nums.size(); ++i){
            sum += nums[i];
            mr = max(sum, mr);
        }
        return max(max(lmax, rmax), ml + mr + nums[m]);
    }
};