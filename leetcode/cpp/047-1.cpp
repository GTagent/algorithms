class Solution {
public:
    // backtraking with group numbers
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> list;
        map<int, int> m;
        for(int i : nums){
            if(m.find(i) == m.end()) m[i] = 0;
            m[i]++;
        }
        permute(nums.size(), list, ans, m);
        return ans;
    }
    void permute(int k, vector<int>& list, vector<vector<int>>& ans, map<int, int>& m){
        if(k <= 0){
            ans.push_back(list);
            return;
        }
        for(auto &p : m){
            if(p.second <= 0){
                continue;
            }
            p.second--;
            list.push_back(p.first);
            permute(k - 1, list, ans, m);
            list.pop_back();
            p.second++;
        }
    }
};