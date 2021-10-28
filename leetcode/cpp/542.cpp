class Solution {
public:
    struct cord{
        int x;
        int y;
    };
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> dir{{-1,0},{0,1},{1,0},{0,-1}};
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dis;
        queue<cord> q;
        for(int i = 0; i < n; ++i){
            vector<int> line;
            for(int j = 0; j < m; ++j){
                if(mat[i][j] == 0){
                    q.push(cord{i, j});
                    line.push_back(0);
                }else{
                    line.push_back(INT_MAX);
                }
            }
            dis.push_back(line);
        }
        while(!q.empty()){
            cord p = q.front();q.pop();
            for(int i = 0; i < dir.size(); ++i){
                int x = p.x + dir[i][0];
                int y = p.y + dir[i][1];
                if(x >=0 && x < n && y >=0 && y < m){
                    if(dis[p.x][p.y] + 1 < dis[x][y]){
                        dis[x][y] = dis[p.x][p.y] + 1;
                        q.push(cord{x, y});
                    }
                }
            }
        }
        return dis;
    }
};