class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        vector<int> path;
        vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1 ,0}};
        int x = 0, y = 0;
        int s = 1;
        matrix[x][y] = s;
        for(int i = 0; i <= n / 2; ++i){
            for(int j = 0; j < 4; ++j){
                int xx = x + dir[j][0];
                int yy = y + dir[j][1];
                while(xx >=0 && xx < n && yy >= 0 && yy < n && !matrix[xx][yy]){
                    x = xx;
                    y = yy;
                    matrix[xx][yy] = ++s;
                    xx = x + dir[j][0];
                    yy = y + dir[j][1];
                }
            }
        }
        return matrix;
    }
};