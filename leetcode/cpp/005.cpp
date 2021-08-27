class Solution {
public:
    string longestPalindrome(string s) {
        int f[1000][1000];
        int st = 0;
        int ed = 0;
        memset(f, 0, sizeof(f));
        int l = s.size();
        for (int i =0; i < l; ++i){
            f[i][i] = 1;
        }
        for (int i = l - 1; i >= 0; --i){
            if (i + 1 >= l)
                continue;
            for (int j = i + 1; j < l; ++j){
                if (i+1 <= j-1)
                    f[i][j] = f[i+1][j-1] & (s[i] == s[j]);
                else
                    f[i][j] = (s[i] == s[j]);
                if (f[i][j] == 1){
                    if (j - i + 1>= ed - st +1){
                        st = i;
                        ed = j;
                    }
                }
            }
        }
        return s.substr(st, ed - st + 1);
    }
};