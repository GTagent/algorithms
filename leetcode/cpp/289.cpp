class Solution {
public:
    int dir[8][2]={{-1,-1},{-1, 0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
    
    int count(vector<vector<int>>& A, int x, int y, int m, int n){
        int cnt = 0;
        for(int i = 0; i < 8; ++i){
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if(xx < 0 || xx >=m || yy < 0 || yy>=n) continue;
            cnt += (A[xx][yy] & 1);
        }
        return cnt;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                int cnt = count(board, i, j, m, n);
                // cout<<i<<" "<<j<<" "<<board[i][j]<<" "<<cnt<<endl;
                if(cnt == 3 || (cnt + board[i][j] == 3))
                   board[i][j] = board[i][j] | 2;
            }
        }
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                board[i][j] >>= 1;
            }
        }
    }
};