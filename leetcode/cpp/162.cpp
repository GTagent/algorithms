class Solution {
public:
    int binSearch(vector<int> & nums, int l, int r){
        if(l == r )
            return l;
        int m = (l + r) >> 1;
        int m2 = m + 1;
        if(nums[m] > nums[m2])
            return binSearch(nums, l, m);
        else
            return binSearch(nums, m2, r);
    }
    int findPeakElement(vector<int>& nums) {
        return binSearch(nums, 0, nums.size() - 1);
    }
};