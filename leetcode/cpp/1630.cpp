class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i = 0; i < l.size(); ++i){
            if(r[i] - l[i] < 2){
                ans.push_back(true);
            }else{
                vector<int> tmp(nums.begin() + l[i], nums.begin() + r[i] + 1);
                sort(tmp.begin(), tmp.end());
                bool check = true;
                for(int j = 2; j < tmp.size(); ++j){
                    if(tmp[j] - tmp[j - 1] != tmp[1] - tmp[0]){
                        check = false;
                        break;
                    }
                }
                ans.push_back(check);
            }
        }
        return ans;
    }
};