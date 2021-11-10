class Solution {
private:
    vector<vector<int>> dir{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
public:
    bool isBoarder(int x, int y, int rows, int cols){
        if(x == 0 || x == rows -1 || y == 0 || y == cols - 1)
            return true;
        else
            return false;
    }
    bool checkAreas(int x, int y, int rows, int cols, vector<vector<char>>& board, vector<vector<int>>& visited){
        vector<pair<int, int>> areas;
        areas.push_back({x, y});
        visited[x][y] = 1;
        stack<pair<int, int>> st;
        st.push({x, y});
        bool ifBoarder = isBoarder(x, y, rows, cols);
        while(!st.empty()){
            pair<int, int> node = st.top();st.pop();
            int xx = node.first;
            int yy = node.second;
            for(int i = 0; i < 4; ++i){
                int xxx = xx + dir[i][0];
                int yyy = yy + dir[i][1];
                if(xxx >= 0 && xxx < rows && yyy >= 0 && yyy < cols && board[xxx][yyy] == 'O' && !visited[xxx][yyy]){
                    visited[xxx][yyy] = 1;
                    st.push({xxx, yyy});
                    areas.push_back({xxx, yyy});
                    ifBoarder = ifBoarder || isBoarder(xxx, yyy, rows, cols);
                }
            }
        }
        if(ifBoarder)
            return false;
        for(pair<int, int> node : areas){
            int xx = node.first;
            int yy = node.second;
            board[xx][yy] = 'X';
        }
        return true;
    }
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols));
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(board[i][j] == 'O' && !visited[i][j]){
                    checkAreas(i, j, rows, cols, board, visited);
                }
            }
        }
    }
};