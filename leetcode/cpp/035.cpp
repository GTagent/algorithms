class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = (l + r) >> 1;
            // cout<<l<<" "<<mid<<" "<<r<<" "<<nums[mid]<<" "<<target<<endl;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};