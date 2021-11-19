class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int f[1010][1010];
        memset(f, 0, sizeof(f));
        for(int i = 0; i < t1.size(); ++i)
            for(int j = 0; j < t2.size(); ++j){
                if(t1[i] == t2[j])
                    f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j] + 1);
                f[i + 1][j + 1] = max(f[i + 1][j + 1], max(f[i][j + 1], f[i + 1][j]));
            }
        return f[t1.size()][t2.size()];
    }
};