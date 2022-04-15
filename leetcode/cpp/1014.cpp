class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int ans = 0;
        int maxsofar = A[0] + 0;
        for(int i = 1; i < A.size(); ++i){
            maxsofar = max(maxsofar, A[i - 1] + (i - 1));
            ans = max(ans, A[i] - i + maxsofar);
        }
        return ans;
    }
};