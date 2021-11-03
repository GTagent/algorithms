class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxheight = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(maxheight >= i){
                maxheight = max(i + nums[i], maxheight);
            }else
                return false;
        }
        return true;
    }
};