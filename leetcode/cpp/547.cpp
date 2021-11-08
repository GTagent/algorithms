class Solution {
private:
    int hash[300];
public:
    void floodfill(vector<vector<int>>& isConnected, int v){
        hash[v] = 1;
        for(int i = 0; i < isConnected[v].size(); ++i){
            if(!hash[i] && isConnected[v][i]){
                floodfill(isConnected, i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        memset(hash, 0, sizeof(hash));
        int ans = 0;
        for(int i = 0; i < isConnected.size(); ++i){
            if(!hash[i]){
                ++ans;
                floodfill(isConnected, i);
            }
        }
        return ans;
    }
};