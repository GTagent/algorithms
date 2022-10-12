class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int x = n - 3, y = n - 2, z = n - 1;
        while(x >= 0 && x < y && y < z){
            if(nums[x] + nums[y] > nums[z]){
                return nums[x] + nums[y] + nums[z];
            }else{
                --z;
                y = z - 1;
                x = y - 1;
            }
        }
        return 0;
    }
};