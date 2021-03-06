class Solution {
public:
    //randomize algorithms
    //code from Jianchao Li's solution in the problem disscuss forum
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), candidate, counter;
        srand(unsigned(time(NULL)));
        while (true) {
            candidate = nums[rand() % n], counter = 0;
            for (int num : nums) {
                if (num == candidate) {
                    counter++;
                }
            }
            if (counter > n / 2) {
                break;
            }
        }
        return candidate;
    }
};