class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
        // int sign = ((dividend < 0 && divisor >0) || (dividend > 0 && divisor < 0))? -1 ; 1;
        int sign = dividend < 0 ^ divisor < 0 ? -1 : 1;
        long dvd = labs(dividend), div = labs(divisor), ans = 0;
        // cout<<dvd<<" "<<div<<endl;
        while(dvd >= div){
            long tmp = div, c = 1;
            while(tmp << 1 <= dvd){
                tmp <<= 1;
                c <<= 1;
            }
            dvd -= tmp;
            ans += c;
        }
        return sign * ans;
    }
};