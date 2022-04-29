class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 2, vector<int>(m + 2, 0));
        int maxx = 0;
        for(int i = 0; i <= n; ++i){
            for(int j = 0; j <= m; ++j){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }else if (s[i - 1] == t[j - 1]){
                    dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
                    maxx = max(maxx, dp[i][j]);
                }else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return maxx == n;
    }
};