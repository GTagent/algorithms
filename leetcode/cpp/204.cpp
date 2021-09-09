class Solution {
public:
    // selective search
    int countPrimes(int n) {
        int m[5000010];
        memset(m, 0, sizeof(m));
        int ans = 0;
        for(int i = 2; i < n ; ++i){
            if(!m[i]){
                ++ans;
                int j = i;
                while(j < n){
                    m[j] = 1;
                    j += i;
                }
            }
        }
        return ans;
    }
};