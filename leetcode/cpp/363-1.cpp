class Solution {
public:
    // brute force
    // use std::vector will be TE
    // use c-style array instead will be AC
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        // vector<vector<int>> sums(m + 1, vector<int>(n + 1, 0));
        int sums[101][101]={0};
        // cout<<sums.size()<<" "<<sums[0].size()<<endl;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                sums[i + 1][j + 1] = matrix[i][j] + sums[i][j + 1] + sums[i + 1][j] - sums[i][j];
            }
        }
        int maxs = -1000000;
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(sums[i][j] < k)
                    maxs = max(maxs, sums[i][j]);
                else if (sums[i][j] == k)
                    return k;
                for(int p = i; p >= 1; --p){
                    for(int q = j; q >= 1; --q){
                        int s = sums[i][j] - sums[i][q - 1] - sums[p - 1][j] + sums[p - 1][q - 1];
                        if(s < k)
                            maxs = max(maxs ,s);
                        else if(s == k){
                            return k;
                        }
                    }
                }
            }
        }
        return maxs;
    }
};