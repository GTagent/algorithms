class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        return (a[0] < b[0]) || ((a[0] == b[0]) && (a[1] > b[1]));
    }
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        sort(prop.begin(), prop.end(), cmp);
        int ans = 0;
        int n = prop.size();
        int maxd = prop[n - 1][1];
        for(int i = n - 2; i >= 0; --i){
            ans += (prop[i][1] < maxd);
            maxd = max(maxd, prop[i][1]);
        }
        return ans;
    }
};