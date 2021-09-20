class Solution {
public:
    int id(int k){
        if(k == 0)
            return 0;
        return (k > 0)? 1 : -1;
    }
    
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int l = 0, lenl = 0;
        int r = 0, lenr = 0;
        int res = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(!l){
                l = 1;
                lenl = 0;
            }
            if(!r){
                r = 1;
                lenr = 0;
            }
            l *= id(nums[i]); ++lenl;
            r *= id(nums[n - i - 1]); ++lenr;
            if(l > 0 && lenl > res) res = lenl;
            if(r > 0 && lenr > res) res = lenr;
        }
        return res;
    }
};