class Solution {
public:
    vector<int> vis;
    vector<int> sets;
    bool floodfill(int k, int s, vector<vector<int>>& graph){
        // cout<<k<<endl;
        sets[k] = s;
        vis[k] = 1;
        for(int n : graph[k]){
            if(sets[n] == s)
                return false;
            else if(sets[n] == 0)
                sets[n] = 3 - s;
        }
        for(int n :graph[k]){
            if(!vis[n] && !floodfill(n, 3 - s, graph))
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vis.resize(n, 0);
        sets.resize(n, 0);
        for(int i = 0; i < n; ++i){
            if(!vis[i] && !floodfill(i, 1, graph)){
                return false;
            }
        }
        return true;
    }
};