class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i){
            int tar = target - nums[i];
            for(int j = i + 1; j < nums.size(); ++j){
                int remain = tar - nums[j];
                int ll = j + 1, rr = nums.size() - 1;
                while(ll < rr){
                    int sum = nums[ll] + nums[rr];
                    if(sum < remain){
                        ++ll;
                    }else if(sum > remain){
                        --rr;
                    }else{
                        vector<int> par{nums[i], nums[j], nums[ll], nums[rr]};
                        ans.push_back(par);
                        while(ll < rr && nums[ll] == par[2]) ++ll;
                        while(ll < rr && nums[rr] == par[3]) --rr;
                    }
                }
                while(j + 1 < nums.size() && nums[j + 1] == nums[j]) ++j;
            }
            while(i + 1 < nums.size() && nums[i + 1] == nums[i]) ++i;
        }
        return ans;
    }
};