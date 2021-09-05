class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int occur = 1;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] == nums[i-1])
                ++occur;
            else{
                if(occur > (nums.size() >> 1))
                    ans = nums[i - 1];
                occur = 1;
            }
        }
        if(occur > (nums.size() >> 1))
            ans = nums[nums.size() - 1];
        return ans;
    }
};