class Solution {
public:
    int divide(vector<int>& nums, int l, int r){
        // cout<<": "<<l<<" "<<r<<endl;
        if(l == r)
            return nums[l];
        if(l > r)
            return INT_MAX;
        if(nums[l] <= nums[r])
            return nums[l];
        int m = (l + r) >> 1;
        // cout<<"X: "<<l<<" "<<r<<" "<<m<<endl;
        int left = divide(nums, l, m);
        int right = divide(nums, m + 1, r);
        return min(left, right);
    }
    int findMin(vector<int>& nums) {
        return divide(nums, 0, nums.size() - 1);
    }
};