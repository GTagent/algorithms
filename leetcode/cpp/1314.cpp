class Solution {
public:
    
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> sum(m + 2, vector<int>(n + 2, 0));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + mat[i][j];
            }
        }
        // cout<<"sum:"<<endl;
        // for(int i = 1; i <= m; ++i){
        //     for(int j = 1; j <= n; ++j){
        //         cout<<sum[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<"-----------------"<<endl;
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                // cout<<i<<" "<<j<<":"<<endl;
                ans[i][j] = sum[min(i + k + 1, m)][min(j + k + 1, n)];
                // cout<<min(i + k + 1, m)<<" "<<min(j + k + 1, n)<<" "<<ans[i][j]<<endl;
                ans[i][j] -= sum[min(i + k + 1, m)][max(j - k, 0)];
                // cout<<min(i + k + 1, m)<<" "<<max(j - k, 0)<<" "<<ans[i][j]<<endl;
                ans[i][j] -= sum[max(i - k, 0)][min(j + k + 1, n)];
                // cout<<max(i - k, 0)<<" "<<min(j + k + 1, n)<<" "<<ans[i][j]<<endl;
                ans[i][j] += sum[max(i - k, 0)][max(j - k, 0)];
                // cout<<max(i - k, 0)<<" "<<max(j - k, 0)<<" "<<ans[i][j]<<endl;
            }
        }
        // cout<<"~~~~~~~~~~~~~~~"<<endl;
        return ans;
    }
};