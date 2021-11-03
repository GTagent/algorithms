class Solution {
public:
    bool isValid(int x, int y, vector<pair<int,int>>& pts, int k){
        for(int i = 0; i < k; ++i){
            int xx = pts[i].first;
            int yy = pts[i].second;
            if(xx == -1 || yy == -1)
                continue;
            if(xx == x || yy == y || (abs(xx -x) == abs(yy - y)))
                return false;
        }
        return true;
    }
    void generateSols(int k, int n, vector<pair<int, int>>& pts, vector<vector<string>>& ans){
        if(k >= n){
            // cout<<"solution: "<<k<<endl;
            // for(int i = 0; i < n; ++i){
            //     cout<<pts[i].first<<" "<<pts[i].second<<endl;
            // }
            vector<string> solution(n, "");
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    solution[i] += ".";
                }
            }
            for(int i = 0; i < k; ++i){
                int x = pts[i].first;
                int y = pts[i].second;
                if(x == -1 || y == -1)
                    continue;
                solution[x][y] = 'Q';
            }
            ans.push_back(solution);
            return;
        }
        int x = k;
        for(int y = 0; y < n; ++y){
            if(isValid(x, y, pts, k)){
                pts[k] = {x, y};
                generateSols(k + 1, n, pts, ans);
                pts[k] = {-1, -1};
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<pair<int, int>> pts(n, {-1, -1});
        generateSols(0, n, pts, ans);
        return ans;
    }
};