class Solution {
public:
    void floodfill(vector<vector<char>>& grid, int x, int y){
        if(x <0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != '1') return;
        grid[x][y] = '0';
        int dir[4][2] ={{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for(int i = 0; i < 4; ++i){
            floodfill(grid, x + dir[i][0], y + dir[i][1]);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == '1'){
                    ++ans;
                    floodfill(grid, i, j);
                }
            }
        }
        return ans;
    }
};