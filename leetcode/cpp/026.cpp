class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int maxi = -200;
        for(int i = 0 ; i < nums.size(); ++i){
            if(nums[i] <= maxi){
                int j = i + 1;
                while(j < nums.size() && nums[j] <= maxi) ++j;
                if(j < nums.size()){
                    maxi = nums[j];
                    nums[i] = nums[j];
                    nums[j] = -200;
                    ++k;
                }
            }else{
                maxi = nums[i];
                ++k;
            }
        }
        return k;
    }
};