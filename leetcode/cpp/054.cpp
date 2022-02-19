class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> hash(m, vector<int>(n, 0));
        vector<int> path;
        vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1 ,0}};
        int x = 0, y = 0;
        hash[x][y] = 1;
        path.push_back(matrix[x][y]);
        for(int i = 0; i <= m / 2; ++i){
            for(int j = 0; j < 4; ++j){
                int xx = x + dir[j][0];
                int yy = y + dir[j][1];
                while(xx >=0 && xx < m && yy >= 0 && yy < n && !hash[xx][yy]){
                    x = xx;
                    y = yy;
                    path.push_back(matrix[x][y]);
                    hash[x][y] = 1;
                    xx = x + dir[j][0];
                    yy = y + dir[j][1];
                }
            }
        }
        return path;
    }
};