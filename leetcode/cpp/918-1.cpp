class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int tsum = 0, maxa = INT_MIN, mina = INT_MAX, sum1 = 0, sum2 = 0; 
        for(auto x: A){
            tsum += x;
            sum1 += x;
            sum2 += x;
            maxa = max(maxa, sum1);
            if(sum1 < 0) sum1 = 0;
            mina = min(mina, sum2);
            if(sum2 > 0) sum2 = 0;
        }
        if(tsum == mina) return maxa;
        return max(maxa, tsum - mina);
    }
};