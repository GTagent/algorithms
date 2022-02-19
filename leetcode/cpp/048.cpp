class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n / 2; ++i){
            for(int j = i; j < n - i - 1; ++j){
                int xx, yy;
                calNext(n, i, j, xx, yy);
                // cout<<"----------"<<endl;
                // cout<<i<<" "<<j<<" "<<matrix[i][j]<<":"<<endl;
                // cout<<xx<<" "<<yy<<" "<<matrix[xx][yy]<<endl;
                swap(matrix[i][j], matrix[xx][yy]);
                while(!(xx == i && yy == j)){
                    calNext(n, xx, yy, xx, yy);
                    // cout<<xx<<" "<<yy<<" "<<matrix[xx][yy]<<endl;
                    swap(matrix[i][j], matrix[xx][yy]);
                }
                // cout<<"----------------"<<endl;
            }
        }
    }
    void calNext(int n, int x, int y, int& xx, int & yy){
        xx = y;
        yy = n - x - 1;
    }
    void swap(int& a, int& b){
        int c = a; a = b; b = c;
    }
};