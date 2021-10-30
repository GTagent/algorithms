class Solution {
public:
    void generate(vector<int>& comb, vector<vector<int>>& ans, int st, int level, int n, int k){
        if(level == k){
            ans.push_back(comb);
            return;
        }
        for(int i = st + 1; i <=n ; ++i){
            comb[level] = i;
            generate(comb, ans, i, level + 1, n , k);
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb(k, 0);
        generate(comb, ans, 0, 0, n, k);
        return ans;
    }
};