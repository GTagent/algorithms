class Solution {
public:
    int hash[50];
    void generate(vector<int>& perm, vector<vector<int>>& ans, vector<int>& nums, int level, int len){
        if(level == len){
            vector<int> comb;
            for(int i = 0; i < len; ++i)
                comb.push_back(nums[perm[i]]);
            ans.push_back(comb);
            return;
        }
        for(int i = 0; i < len; ++i){
            if(!hash[i]){
                hash[i] = 1;
                perm[level] = i;
                generate(perm, ans, nums, level + 1, len);
                hash[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> ans;
        vector<int> perm(len, 0);
        generate(perm, ans, nums, 0, len);
        return ans;
    }
};