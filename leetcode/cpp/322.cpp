class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // if(amount == 0) return 0;
        int max_int = INT_MAX - 1000000;
        int n = coins.size();
        vector<int> f(10100, max_int);
        sort(coins.begin(), coins.end());
        f[0] = 0;
        // cout<<1<<endl;
        for(int i = n - 1; i >=0; --i){
            for(int j = coins[i]; j <= amount; ++j){
                if(f[j - coins[i]] + 1 < f[j]){
                    f[j] = f[j - coins[i]] + 1;
                    // cout<<i<<" "<<coins[i]<<" "<<j<<" "<<j-coins[i]<<" "<<f[j - coins[i]]<<endl;
                }
            }
        }
        if(f[amount] == max_int)
            return -1;
        else
            return f[amount];
    }
};