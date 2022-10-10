class Solution {
public:
    int modi = (int)1e9 + 7;
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> f(n + 1, vector<int>(target + 1, 0));
        f[0][0] = 1;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= min(i * k, target); ++j){
                f[i][j] = 0;
                for(int l = 1; l <= k; ++l){
                    if(j - l >= 0)
                        f[i][j] = (f[i][j] + f[i - 1][j - l]) % modi;
                }
            }
        }
        return f[n][target];
    }
};