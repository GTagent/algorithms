class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for(int i = 0; i < nums.size(); ++ i){
            if(nums[i] != val)
                ++k;
            else{
                int j = i + 1;
                while(j < nums.size() && nums[j] == val) ++j;
                if(j < nums.size() && nums[j] != val){
                    nums[i] = nums[j];
                    nums[j] = val;
                    ++k;
                }else
                    break;
            }
        }
        return k;
    }
};