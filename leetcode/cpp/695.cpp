class Solution {
public:
    void fill(vector<vector<int>>& grid, int sr, int sc , int& cnt){
        // cout<<"fst:("<<sr<<" "<<sc<<")"<<endl;
        if(sr < 0 || sr >= grid.size() || sc < 0 || sc >= grid[0].size() || grid[sr][sc] != 1) return;
        // cout<<sr<<" "<<sc<<" "<<grid[sr][sc]<<endl;
        grid[sr][sc] = -1;
        ++cnt;
        vector<vector<int>> dir{{-1,0},{0, 1},{1,0},{0,-1}};
        for(int i = 0; i < dir.size(); ++i){
            fill(grid, sr + dir[i][0], sc + dir[i][1], cnt);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 1){
                    int cnt = 0;
                    // cout<<"----------------------"<<endl;
                    fill(grid, i, j, cnt);
                    // cout<<"----------------------"<<endl;
                    if(cnt > ans)
                        ans = cnt;
                }
            }
        }
        return ans;
    }
};