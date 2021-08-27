class Solution {
public:
    void swap(vector<int> & nums, int a, int b){
        int t = nums[a];nums[a] = nums[b];nums[b] = t;
    }
    void quicksort(vector<int>& nums, int l, int r){
        if(l >= r) return;
        int i = l, j = r - 1, p = r;
        while(i < j){
            while(i <= r - 1 && nums[i] <= nums[p]) ++i;
            while(j >= l && nums[j] >= nums[p]) --j;
            if(i < j){
                swap(nums, i, j);
            }
        }
        if(nums[i] > nums[p])
            swap(nums, i, p);
        quicksort(nums, l, i - 1);
        quicksort(nums, i + 1, r);
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        // quicksort(nums, 0, nums.size() - 1);
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); ++i){
            int target = -nums[i];
            int ll = i + 1;
            int rr = nums.size() - 1;
            while(ll < rr){
                int sum = nums[ll] + nums[rr];
                if(sum < target)
                    ++ll;
                else if(sum > target)
                    --rr;
                else{
                    vector<int> p{nums[i], nums[ll], nums[rr]};
                    ans.push_back(p);
                    while(ll < rr && nums[ll] == p[1]) ++ll;
                    while(ll < rr && nums[rr] == p[2]) --rr;
                }
            }
            while(i + 1 <nums.size() && nums[i + 1] == nums[i]) ++i;
        }
        return ans;
    }
};