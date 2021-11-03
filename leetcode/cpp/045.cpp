class Solution {
public:
    int min(int a, int b){return a < b?a:b;}
    int jump(vector<int>& nums) {
        if(nums.size() <= 1)
            return 0;
        int cnt = 0;
        int height = 0;
        int i = 0;
        while(i < nums.size()){
            int maxh = 0;
            for(int j = i; j <= min(nums.size() - 1, height); ++j)
                maxh = max(nums[j] + j, maxh);
            ++cnt;
            if(maxh >= nums.size() - 1)
                break;
            i = height + 1;
            height = maxh;
        }
        return cnt;
    }
};