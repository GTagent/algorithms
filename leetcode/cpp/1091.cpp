class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int max_int = INT_MAX - 1000000;
        vector<vector<int>> hash(rows, vector<int>(cols, max_int));
        vector<vector<int>> dir{{0, -1},{-1, -1},{-1, 0},{-1, 1},{0, 1},{1,1},{1,0},{1, -1}};
        queue<pair<int, int>> q;
        if(grid[0][0] == 0){
            q.push({0, 0});
            hash[0][0] = 1;
        }
        while(!q.empty()){
            pair<int, int> v = q.front();q.pop();
            int x = v.first;
            int y = v.second;
            for(int i = 0; i < dir.size(); ++i){
                int xx = x + dir[i][0];
                int yy = y + dir[i][1];
                if(xx >= 0 && xx < rows && yy >= 0 && yy < cols && grid[xx][yy] == 0){
                    if(hash[x][y] + 1 < hash[xx][yy]){
                        q.push({xx, yy});
                        hash[xx][yy] = hash[x][y] + 1;
                        if(xx == rows -1 && yy == cols - 1){
                            break;
                        }
                    }
                }
            }
        }
        if(hash[rows - 1][cols - 1] == max_int)
            return - 1;
        else
            return hash[rows - 1][cols - 1];
    }
};