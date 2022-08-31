class Solution {
public:
    struct element{
        int val;
        int x,y;
        int diag;
    };
    
    static bool compEle(const element &a, const element & b){
        return a.val < b.val;
    }
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<element> arr(m * n);
        int k = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                arr[k].val = mat[i][j];
                arr[k].x = i;
                arr[k].y = j;
                arr[k].diag = i - j;
                ++k;
            }
        }
        sort(arr.begin(), arr.end(), compEle);
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for(auto ele : arr){
            int diag = ele.diag;
            int x = 0;
            int y = 0;
            if(diag <= 0){
                y = -diag;
            }else{
                x = diag;
            }
            while(ans[x][y] != 0 && x < n && y < m){++x,++y;}
            ans[x][y] = ele.val;
        }
        return ans;
    }
};