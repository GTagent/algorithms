class Solution {
public:
    int minCost(string colors, vector<int>& ntime) {
        int maxTime = ntime[0];
        int ans = 0;
        for(int i = 1; i < colors.size(); ++i){
            if(colors[i] == colors[i - 1]){
                if(ntime[i] > maxTime){
                    ans += maxTime;
                    maxTime = ntime[i];
                }else{
                    ans += ntime[i];
                }
            }else{
                maxTime = ntime[i];
            }
        }
        return ans;
    }
};