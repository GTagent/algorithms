class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int res = INT_MAX, min_n = INT_MAX;
        priority_queue<int> pq;
        for(auto n : nums){
            n = (n & 1)? (n << 1): n;
            pq.push(n);
            min_n = min(min_n, n);
        }
        while((pq.top() & 1) == 0){
            res = min(res, pq.top() - min_n);
            min_n = min(min_n, pq.top() >> 1);
            pq.push(pq.top() >> 1);
            pq.pop();
        }
        return min(res, pq.top() - min_n);
    }
};