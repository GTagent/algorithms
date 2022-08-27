class Solution {
public:
    // binary search
    // colume way
    // Thanks to https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/discuss/2488222/Faster-oror-Easy-To-Understand-oror-C%2B%2B-Code
    int findMaxSum(const vector<int>& arr, int k){
        int maxi = INT_MIN;
        set<int> s;
        s.insert(0);
        int curSum = 0;
        int n = arr.size();
        for(int i = 0; i < n; ++i){
            curSum += arr[i];
            auto iter = s.lower_bound(curSum - k);
            if(iter != s.end()){
                maxi = max(maxi, curSum - *iter);
            }
            s.insert(curSum);
        }
        return maxi;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxi = INT_MIN;
        for(int startCol = 0; startCol < n; ++startCol){
            vector<int> sums(m, 0);
            for(int endCol = startCol; endCol < n; ++endCol){
                for(int row = 0; row < m; ++row){
                    sums[row] += matrix[row][endCol];
                }
                
                int tmp = findMaxSum(sums, k);
                maxi = max(maxi, tmp);
            }
        }
        return maxi;
    }
};