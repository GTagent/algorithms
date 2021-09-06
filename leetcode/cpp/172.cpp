class Solution {
public:
    int trailingZeroes(int n) {
        int sum2 = 0, sum5 = 0;
        for(int i = 2; i <= n; ++i){
            int x = i;
            while(x % 2 == 0){
                ++sum2;
                x = x / 2;
            }
            x = i;
            while(x % 5 == 0){
                ++sum5;
                x = x / 5;
            }
        }
        // cout<<sum2<<" "<<sum5<<endl;
        return min(sum2, sum5);
    }
};