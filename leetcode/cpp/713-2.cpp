class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int mul = 1;
        int counter = 0;
        for(int i = 0; i < nums.size(); ++i){
            int front = i - counter;
            mul *= nums[i];
            while(front <= i && mul >= k){
                mul /= nums[front];
                ++front;
            }
            if(front > i){
                counter = 0;
                mul = 1;
            }else{
                counter = i - front + 1;
                ans += i - front + 1;
            }
        }
        return ans;
    }
};