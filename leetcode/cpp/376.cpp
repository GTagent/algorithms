class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 2, 0);
        vector<int> g(n + 2, 0);
        int ans = 1;
        f[0] = g[0] = 1;
        for(int i = 1; i < n; ++i){
            f[i] = g[i] = 1;
            for(int j = 0; j < i; ++j){
                if(nums[j] < nums[i]){
                    f[i] = max(f[i], g[j] + 1);
                }
                if(nums[j] > nums[i]){
                    g[i] = max(g[i], f[j] + 1);
                }
            }
            ans = max(ans, max(f[i], g[i]));
        }
        return ans;
    }
};