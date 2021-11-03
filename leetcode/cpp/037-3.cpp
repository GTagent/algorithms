class Solution {
private:
    int hr[9][256], hc[9][256], hd[3][3][256];
    int rows = 9;
    int cols = 9;
public:
    bool genSudo(int x, int y, vector<vector<char>>& board){
        if(x >= rows) return true;
        if(y >= cols) return genSudo(x + 1, 0, board);
        if(board[x][y] != '.') return genSudo(x, y + 1, board);
        
        for(char c = '1'; c <= '9'; ++c){
            if(isValid(x, y, c)){
                hr[x][c] = 1;
                hc[y][c] = 1;
                hd[x/3][y/3][c] = 1;
                board[x][y] = c;
                if(genSudo(x, y + 1, board))
                    return true;
                hr[x][c] = 0;
                hc[y][c] = 0;
                hd[x/3][y/3][c] = 0;
                board[x][y] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        memset(hr, 0, sizeof(hr));
        memset(hc, 0, sizeof(hc));
        memset(hd, 0, sizeof(hd));
        
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(board[i][j] != '.'){
                    char c = board[i][j];
                    hr[i][c] = 1;
                    hc[j][c] = 1;
                    hd[i/3][j/3][c] = 1;
                }
            }
        }
        
        genSudo(0, 0, board);
    }
private:
    bool isValid(int x, int y, char c){
        if(hr[x][c] || hc[y][c] || hd[x/3][y/3][c])
            return false;
        else
            return true;
    }
};