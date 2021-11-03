class Solution {
public:
    int rows = 9;
    int cols = 9;
    int dists = 9;
    vector<map<int, int>> h_rows = vector<map<int, int>>(rows);
    vector<map<int, int>> h_cols = vector<map<int, int>>(cols);
    vector<map<int, int>> h_dist = vector<map<int, int>>(dists);
    
    struct potential{
        int k;
        int x,y;
        vector<int> pot;
    };
    static bool potComp(const potential &x, const potential &y){
        return (x.k < y.k);
    }
    int calcDist(int x, int y){
        return (int)(x/3) * 3 + (int)(y/3);
    }
    bool isContain(int k, map<int, int>& m){
        return (m.find(k) == m.end()) || (!m[k]);
    }
    bool checkValid(int k, int x, int y){
        int dist = calcDist(x, y);
        return isContain(k, h_rows[x]) && isContain(k, h_cols[y]) && isContain(k, h_dist[dist]);
    }
    bool genSolu(int k, vector<potential>& pots, vector<vector<char>>& board){
        if(k >= pots.size()){
            return true;
        }
        potential p = pots[k];
        int x = p.x;
        int y = p.y;
        for(int i = 0; i < p.k; ++i){
            int num = p.pot[i];
            if(checkValid(num, x, y)){
                board[x][y] = (char)(num + '0');
                h_rows[x][num] = 1;
                h_cols[y][num] = 1;
                int dist = calcDist(x, y);
                h_dist[dist][num] = 1;
                if(genSolu(k + 1, pots, board))
                    return true;
                board[x][y] = '.';
                h_rows[x][num] = 0;
                h_cols[y][num] = 0;
                h_dist[dist][num] = 0;
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<potential> pots;
        for(int i = 0; i < rows; ++i)
            for(int j = 0; j < cols; ++j){
                if(board[i][j] == '.'){
                    potential p;
                    p.x = i;
                    p.y = j;
                    pots.push_back(p);
                }else{
                    int num = board[i][j] - '0';
                    h_rows[i][num] = 1;
                    h_cols[j][num] = 1;
                    int dis = calcDist(i, j);
                    h_dist[dis][num] = 1;
                }
            }
        for(int i = 0; i < pots.size(); ++i){
            pots[i].k = 0;
            int x = pots[i].x;
            int y = pots[i].y;;
            for(int j = 1; j <= 9; ++j){
                if(h_rows[x].find(j) == h_rows[x].end()){
                    if(h_cols[y].find(j) == h_cols[y].end()){
                        int dis = calcDist(x, y);
                        if(h_dist[dis].find(j) == h_dist[dis].find(j)){
                            ++pots[i].k;
                            pots[i].pot.push_back(j);
                        }
                    }
                }
            }
        }
        // sort(pots.begin(), pots.end(), potComp);
        genSolu(0, pots, board);
    }
};