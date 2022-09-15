class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        int n = changed.size();
        if(n & 1)
            return {};
        sort(changed.begin(), changed.end());
        unordered_map<int, int> hash;
        vector<int> ans;
        for(auto ele : changed){
            ++hash[ele];
        }
        for(auto ele : changed){
            if(hash[ele] == 0) continue;
            if(hash[ele << 1] == 0) return {};
            ans.push_back(ele);
            --hash[ele];
            --hash[ele << 1];
        }
        return ans;
    }
};