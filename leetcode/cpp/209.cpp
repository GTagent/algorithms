class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = 0;
        int sum = 0;
        int counter = 0;
        for(int i = 0; i < nums.size(); ++i){
            int front = i - counter;
            sum += nums[i];
            while(front < i && sum - nums[front] >= target){
                sum -= nums[front];
                ++front;
            }
            counter = i - front + 1;
            if(sum >= target)
                ans = (ans == 0)? counter : min(ans, counter);
        }
        return ans;
    }
};