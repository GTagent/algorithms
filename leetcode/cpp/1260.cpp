class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> sequence;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                sequence.push_back(grid[i][j]);
            }
        }
        vector<vector<int>> sgrid(m, vector<int>(n, 0));
        for(int i = 0; i < sequence.size(); ++i){
            int l = (i + k) % (m * n);
            sgrid[(int)(l / n)][(int)(l % n)] = sequence[i];
        }
        return sgrid;
    }
};