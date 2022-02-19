class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x = rStart, y = cStart;
        int cnt = 0, step = 0;
        while(cnt < rows * cols){
            int xx = x, yy = y;
            ++step;
            for(int j = yy; j < yy + step; ++j){
                if(xx >= 0 && xx < rows && j >= 0 && j < cols){
                    ans.push_back(vector<int>{xx, j});
                    ++cnt;
                }
            }
            yy = yy + step;
            for(int i = xx; i < xx + step; ++i){
                if(i >= 0 && i < rows && yy >= 0 && yy < cols){
                    ans.push_back(vector<int>{i, yy});
                    ++cnt;
                }
            }
            xx = xx + step;
            ++step;
            for(int j = yy; j > (yy - step); --j){
                if(xx >= 0 && xx < rows && j >= 0 && j < cols){
                    ans.push_back(vector<int>{xx, j});
                    ++cnt;
                } 
            }
            yy = yy - step;
            for(int i = xx; i > xx - step; --i){
                if(i >= 0 && i < rows && yy >= 0 && yy < cols){
                    ans.push_back(vector<int>{i, yy});
                    ++cnt;
                }
            }
            xx = xx - step;
            x = xx; y = yy;
        }
        return ans;
    }
};
