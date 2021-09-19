class Solution {
public:
    // f[n][2]:
    // f[n][0] means do not take the nth number
    // f[n][1] means take the nth number
    int deleteAndEarn(vector<int>& nums) {
        vector<int> numbers;
        vector<int> amount;
        sort(nums.begin(), nums.end());
        int k = 0;
        numbers.push_back(nums[0]);
        amount.push_back(1);
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] == nums[i - 1]){
                ++amount[k];
            }else{
                numbers.push_back(nums[i]);
                amount.push_back(1);
                ++k;
            }
        }
        // cout<<k + 1<<endl;
        // for(int i = 0; i <=k; ++i){
        //     cout<<numbers[i]<<" "<<amount[i]<<endl;
        // }
        vector<vector<int>> f(nums.size() + 10, vector<int>(2));
        f[0][0] = f[0][1] = f[1][0] = 0;
        f[1][1] = numbers[0] * amount[0];
        for(int i = 1; i <= k; ++i){
            f[i + 1][0] = max(f[i][0], f[i][1]);
            if(numbers[i] - numbers[i - 1] > 1){
                f[i + 1][1] = max(f[i][0], f[i][1]) + numbers[i] * amount[i];
            }else{
                f[i + 1][1] = max(f[i][0] + numbers[i] * amount[i], f[i][1]);
            }
        }
        return max(f[k + 1][0], f[k + 1][1]);
    }
};