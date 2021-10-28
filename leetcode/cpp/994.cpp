class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dis(rows, vector<int>(cols, INT_MAX - 100000));
        int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        queue<pair<int, int>> q;
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(grid[i][j] == 2){
                    dis[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()){
            pair<int, int> cord = q.front();q.pop();
            for(int i = 0; i < 4; ++i){
                int x = cord.first + dir[i][0];
                int y = cord.second + dir[i][1];
                if(x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 1){
                    if(dis[cord.first][cord.second] + 1 < dis[x][y]){
                        dis[x][y] = dis[cord.first][cord.second] + 1;
                        q.push({x, y});
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(grid[i][j] && dis[i][j] == (INT_MAX - 100000)) return -1;
                if(grid[i][j])
                    ans = max(ans, dis[i][j]);
            }
        }
        return ans;
    }
};