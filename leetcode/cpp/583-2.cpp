class Solution {
public:
    // lcs
    int minDistance(string w1, string w2) {
        int f[510][510];
        for(int i = 1; i <= w1.size(); ++i)
            for(int j = 1; j <= w2.size(); ++j){
                if(w1[i - 1] == w2[j - 1])
                    f[i][j] = f[i - 1][j - 1] + 1;
                else
                    f[i][j] = max(f[i][j - 1], f[i - 1][j]);
            }
        return w1.size() + w2.size() - 2 * f[w1.size()][w2.size()];
    }
};