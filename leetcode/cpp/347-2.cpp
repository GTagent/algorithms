class Solution {
    // quickselect
private:
    vector<int> unique;
    map<int, int> counts;
public:
    
    int partition(int left, int right, int idx){
        int pivot = counts[unique[idx]];
        swap(unique[idx], unique[right]);
        
        int m = left;
        for(int i = left; i <= right; ++i){
            if(counts[unique[i]] < pivot){
                swap(unique[m], unique[i]);
                ++m;
            }
        }
        
        swap(unique[right], unique[m]);
        
        return m;
    }
    
    void quickselect(int left, int right, int k_smallest){
        if(left >= right) return;
        int idx = left + rand() % (right - left + 1);
        idx = partition(left, right, idx);
        if(k_smallest == idx){
            return;
        }else if (k_smallest < idx){
            quickselect(left, idx - 1, k_smallest);
        }else{
            quickselect(idx + 1, right, k_smallest);
        }
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(k == nums.size())
            return nums;
        
        for(int n : nums){
            counts[n] += 1;
        }
        
        for (pair<int, int> p : counts){
            unique.push_back(p.first);
        }
        int n = counts.size();
        
        quickselect(0, n - 1, n - k);
        vector<int> top(k);
        copy(unique.begin() + n - k, unique.end(), top.begin());
        return top;
    }
};