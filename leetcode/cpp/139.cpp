class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = 1;
        for(int i = 1; i <= s.size(); ++i){
            for(int j = i - 1; j >= 0; --j){
                if(dp[j]){
                    string sub = s.substr(j, i - j);
                    auto it = find(wordDict.begin(), wordDict.end(), sub);
                    if(it != wordDict.end()){
                        dp[i] = 1;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};