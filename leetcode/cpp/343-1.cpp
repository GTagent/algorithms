class Solution {
public:
    int integerBreak(int n) {
        int ans = 1;
        for(int i = 2; i <= n; ++i){
            int p = n / i;
            if(p < 1)
                break;
            int r = n % i;
            // cout<<i<<" "<<p<<" "<<r<<" "<<n<<" "<<ans<<endl;
            int tmp = 1;
            for(int j = 1; j <= i - r; ++j)
                tmp *= p;
            for(int j = 1; j <= r; ++j)
                tmp *= (p + 1);
            if(tmp > ans)
                ans = tmp;
        }
        return ans;
    }
};  