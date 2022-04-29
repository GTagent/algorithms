class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1)
            return 1;
        priority_queue<long long int, vector<long long int>, greater<long long int>> heap;
        heap.push(1);
        long long int ugly = 1;
        for(int i = 1; i <= n; ++i){
            long long int top = heap.top();
            while(!heap.empty() && heap.top() == top) heap.pop();
            ugly = top;
            // cout<<ugly<<endl;
            heap.push(top * 2);
            heap.push(top * 3);
            heap.push(top * 5);
        }
        return ugly;
    }
};