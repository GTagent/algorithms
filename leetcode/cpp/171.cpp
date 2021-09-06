class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long ans = 0;
        for(long long i = columnTitle.size() - 1, x = 1; i >= 0; i--, x *= 26)
            ans += ((int)(columnTitle[i] - 'A') + 1) * x;
        return ans;
    }
};