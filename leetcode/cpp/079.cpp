class Solution {
private:
    int hash[20][20];
    int dir[4][2]{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
public:
    bool exist(vector<vector<char>>& board, string word) {
        memset(hash, 0, sizeof(hash));
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(checkGrid(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
    bool checkGrid(vector<vector<char>>& board, int x, int y, string word, int k){
        if(k >= word.size()) return true;
        if(x <0 || x >= board.size() || y < 0 || y >= board[0].size() || hash[x][y]) return false;
        if(board[x][y] != word[k]) return false;
        hash[x][y] = 1;
        for(int i = 0; i < 4; ++i){
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if(checkGrid(board, xx, yy, word, k + 1))
                return true;
        }
        hash[x][y] = 0;
        return false;
    }
};