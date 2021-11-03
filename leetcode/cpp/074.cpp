class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int rl = 0, rr = rows - 1;
        while(rl <= rr){
            int rm = (rl + rr) >> 1;
            // cout<<"r: "<<rl<<" "<<rr<<" "<<rm<<" ([0]:"<<matrix[rm][0]<<", [end]:"<<matrix[rm][cols - 1]<<")"<<endl;
            if(matrix[rm][0] <= target && target <= matrix[rm][cols - 1]){
                int cl = 0, cr = cols - 1;
                while(cl <= cr){
                    int cm = (cl + cr) >> 1;
                    if(matrix[rm][cm] == target)
                        return true;
                    if(matrix[rm][cm] < target)
                        cl = cm + 1;
                    else
                        cr = cm - 1;
                }
                return false;
            }
            if(target < matrix[rm][0])
                rr = rm - 1;
            else if (target > matrix[rm][cols - 1]){
                rl = rm + 1;
            }
        }
        return false;
    }
};