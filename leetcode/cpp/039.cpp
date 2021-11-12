class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> list;
        generate(list, candidates, 0, 0, target, ans);
        return ans;
    }
    void generate(vector<int>& list, vector<int>& can, int k, int sum, int target, vector<vector<int>>& ans){
        if(sum >=target){
            if(sum == target){
                ans.push_back(list);
            }
            return;
        }
        for(int i = k; i < can.size(); ++i){
            if(sum + can[i] > target)
                break;
            list.push_back(can[i]);
            generate(list, can, i, sum + can[i], target, ans);
            list.pop_back();
        }
    }
};