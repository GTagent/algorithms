class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int sum = 0;
        for (int i : A) sum += i;
        
        int sum1 = maxSubarraySum(A.begin(), A.end());
        for (int& i : A) i *= -1;
        int sum2 = sum + maxSubarraySum(A.begin(), A.end());
        if(sum2 == 0)
            return sum1;
        return max(sum1, sum2);
    }
    
    int maxSubarraySum(vector<int>::iterator p, vector<int>::iterator q) {
        if (p >= q)
            return 0;
        int result = *p;
        int f = *p;
        for (auto i = p + 1; i != q; i++) {
            if(f < 0)
                f = 0;
            f += *i;
            result = max(result, f);
        }
        return result;
    }
};