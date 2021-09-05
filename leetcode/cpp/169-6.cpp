class Solution {
public:
    //Boyer-Moore Voting Algorithm
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int candidate = 0;
        for(int i = 1; i < nums.size(); ++i){
            if(count == 0)
                candidate = i;
            count += (nums[i] == nums[candidate]) ? 1 : -1;
        }
        return nums[candidate];
    }
}; 