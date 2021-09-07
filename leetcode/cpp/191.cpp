class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        for(uint32_t i = 0, j = 1; i < 32; ++i, j = j << 1)
            sum += (n & j)? 1 : 0;
        return sum;
    }
};