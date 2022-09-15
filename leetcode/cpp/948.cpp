class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        if(n == 0)
            return 0;
        sort(tokens.begin(), tokens.end());
        if(power < tokens[0])
            return 0;
        int hash[1010];
        memset(hash, 0, sizeof(hash));
        int ans = 0;
        int s = 0, p = power;
        int l = 0, r = n - 1;
        while(l <= r){
            while(l <= r && p >= tokens[l]){
                if(!hash[l]){
                    hash[l] = 1;
                    p -= tokens[l];
                    ++s;
                }
                ++l;
            }
            ans = max(ans, s);
            while(s && r < n && r >= l && hash[r]) --r;
            if(s && r >= l && !hash[r]){
                --s;
                p += tokens[r];
                hash[r] = 1;
            }
        }
        return ans;
    }
};
