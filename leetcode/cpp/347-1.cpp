class Solution {
public:
    // heap
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(k == nums.size())
            return nums;
        
        map<int,int> counts;
        for(int n : nums){
            counts[n] += 1;
        }
        
        auto cmp = [&counts](int n1, int n2){ return counts[n1] > counts[n2];};
        priority_queue<int, vector<int>, decltype(cmp)> heap(cmp);
        
        for (pair<int, int> p : counts){
            heap.push(p.first);
            if(heap.size() > k) heap.pop();
        }
        
        vector<int> top(k);
        for(int i = 0; i < k; ++i){
            top[i] = heap.top();
            heap.pop();
        }
        return top;
    }
};