class Solution {
public:
    int modi = (int)1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> arr;
        priority_queue<int, vector<int>, greater<int>> heap;
        for(int i = 0; i < n; ++i){
            arr.push_back(pair<int,int>{efficiency[i], speed[i]});
        }
        sort(arr.rbegin(), arr.rend());
        long totSpd = 0, ans = 0;
        for(int i = 0; i < n; ++i){
            int curEffi = arr[i].first;
            int curSpd = arr[i].second;
            if(heap.size() >= k){
                int tmp = heap.top();heap.pop();
                totSpd -= tmp;
            }
            totSpd += curSpd;
            heap.push(curSpd);
            ans = max(ans, curEffi * totSpd);
        }
        return ans % modi;
    }
};