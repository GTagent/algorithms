class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> list;
        gen_subsets(ans, list, nums, 0);
        return ans;
    }
    void gen_subsets(vector<vector<int>>& ans, vector<int>& list, vector<int>& nums, int k){
        ans.push_back(list);
        for(int i = k; i < nums.size(); ++i){
            list.push_back(nums[i]);
            gen_subsets(ans, list, nums, i + 1);
            list.pop_back();
        }
    }
};