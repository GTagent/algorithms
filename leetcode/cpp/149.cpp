class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1;
        for(int i = 0; i < points.size(); ++i){
            map<double, int> cnt;
            int max_cnt = 0;
            for(int j = 0; j < points.size(); ++j){
                if(i == j) continue;
                double y = (double)points[j][1] - (double)points[i][1];
                double x = (double)points[j][0] - (double)points[i][0];
                ++cnt[y / x];
                max_cnt = max(max_cnt, cnt[y / x]);
            }
            ans = max(ans, max_cnt + 1);
        }
        return ans;
    }
};