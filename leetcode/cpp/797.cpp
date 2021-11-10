class Solution {
public:
    void allPaths(vector<vector<int>>& graph, int d, int k, int target, vector<int>& path, vector<vector<int>>& paths){
        if(d == target){
            vector<int> ans;
            ans.push_back(0);
            for(int i = 1; i < path.size(); ++i)
                if(path[i])
                    ans.push_back(path[i]);
                else
                    break;
            paths.push_back(ans);
            return;
        }
        for(int i = 0; i < graph[d].size(); ++i){
            int n = graph[d][i];
            path[k] = n;
            allPaths(graph, n, k + 1, target, path, paths);
            path[k] = 0;
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> paths;
        vector<int> path(n);
        path[0] = 0;
        allPaths(graph, 0, 1, n - 1, path, paths);
        return paths;
    }
};