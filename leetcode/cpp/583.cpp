class Solution {
public:
    //dp
    int minDistance(string w1, string w2) {
        int f[510][510];
        for(int i = 0; i <= w1.size(); ++i)
            f[i][0] = i;
        for(int j = 0; j <= w2.size(); ++j)
            f[0][j] = j;
        f[0][0] = 0;
        for(int i = 0; i < w1.size(); ++i){
            for(int j = 0; j < w2.size(); ++j){
                if(w1[i] != w2[j]){
                    f[i + 1][j + 1] = min(f[i][j + 1], f[i + 1][j]) + 1;
                }else{
                    f[i + 1][j + 1] = f[i][j];
                }
            }
        }
        return f[w1.size()][w2.size()];
    }
};