class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0)
            return vector<string>{};
        vector<string> ans;
        int i = 0;
        while(i < nums.size()){
            int j = i;
            while(j + 1 < nums.size() && nums[j + 1] == nums[j] + 1) ++j;
            if(i == j){
                string s = to_string(nums[i]);
                ans.push_back(s);
                ++i;
            }else{
                string s = to_string(nums[i]) + "->" + to_string(nums[j]);
                i = j + 1;
                ans.push_back(s);
            }
        }
        return ans;
    }
};