class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxf = 1;
        vector<int> f(n, 1);
        vector<int> g(n, 0);
        g[0] = 1;
        for(int i = 1; i < nums.size(); ++i){
            int k = 0;
            for(int j = 0; j < i; ++j)
                if(nums[j] < nums[i] && f[j] > k)
                    k = f[j];
            f[i] = k + 1;
            g[i] = 0;
            for(int j = 0; j < i; ++j)
                if(nums[j] < nums[i] && f[j] == k)
                    g[i] += g[j];
            if(!g[i])
                g[i] = 1;
            maxf = max(maxf, f[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; ++i)
            if(f[i] == maxf)
                ans += g[i];
        return ans;
    }
};