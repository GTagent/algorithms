class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 1000000;
        for(int i = 0; i < nums.size() - 2; ++i){
            // int remains = target - nums[i];
            int ll = i + 1, rr = nums.size() - 1;
            while(ll < rr){
                int sum = nums[ll] + nums[rr];
                // cout<<nums[i]<<" "<<nums[ll]<<" "<<nums[rr]<<" "<<nums[i] + sum<<" "<<ans<<endl;
                if(abs(target - nums[i] - sum) < abs(ans - target))
                    ans = nums[i] + sum;
                if(sum < target - nums[i]){
                    ++ll;
                }else if(sum > target - nums[i]){
                    --rr;
                }else{
                    return target;
                }
            }
        }
        return ans;
    }
};