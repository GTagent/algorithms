class Solution {
public:
    int rot_id(int id, int len, int k){
        if (id <= k - 1){
            return (id + len - k);
        }else{
            return id - k;
        }
    }
    
    int find_rot(vector<int>& nums){
        if(nums.size() <= 1) return 0;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] < nums[i - 1]){
                return (nums.size() - i);
            }
        }
        return 0;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int k = find_rot(nums);
        // cout<<n<<" "<<k<<endl;
        int l = 0, r = n - 1;
        while(l <= r){
            int m = (l + r) >> 1;
            int rot_m  = rot_id(m, n, k);
            // cout<<":"<<m<<" "<<rot_m<<" "<<nums[rot_m]<<" "<<l<<" "<<r<<endl;
            if(nums[rot_m] == target)
                return rot_m;
            if(nums[rot_m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
};