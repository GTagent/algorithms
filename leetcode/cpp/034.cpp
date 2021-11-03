class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto low = lower_bound(nums.begin(), nums.end(), target);
        if(low  == nums.end())
            return vector<int>{-1, -1};
        int key = low - nums.begin();
        // cout<<key<<endl;
        if(nums[key] > target)
            return vector<int>{-1, -1};
        int fst = key;
        int snd = key;
        for(int i = fst; i < nums.size(); ++i){
            if(nums[i] == target)
                snd = i;
            else
                break;
        }
        vector<int> ans;
        ans.push_back(fst);
        ans.push_back(snd);
        return ans;
    }
};