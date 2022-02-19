class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        if(n < 0){
            return 1/x * myPow(1/x, -(n + 1));
        }
        double t = myPow(x, n >> 1);
        if(n & 1)
            return t * t * x;
        else
            return t * t;
    }
};