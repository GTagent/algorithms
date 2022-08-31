class Solution {
public:
    
    vector<vector<int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    void flow(vector<vector<bool>>& occean, vector<vector<int>> h, int x, int y,int n, int m){
        if(occean[x][y]) return;
        occean[x][y] = true;
        for(int i = 0; i < dir.size(); ++i){
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if(xx >= 0 && xx < n && yy >= 0 && yy < m){
                if(!occean[xx][yy] && h[xx][yy] >= h[x][y])
                    flow(occean, h, xx, yy, n, m);
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> paci(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));
        for(int i = 0; i < n; ++i){
            flow(paci, heights, i, 0, n, m);
            flow(atl, heights, i, m - 1, n, m);
        }
        for(int i = 0; i < m; ++i){
            flow(paci, heights, 0, i, n, m);
            flow(atl, heights, n - 1, i, n, m);
        }
        vector<vector<int>> ans;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(paci[i][j] && atl[i][j])
                    ans.push_back(vector<int>{i, j});
            }
        }
        return ans;
    }
};