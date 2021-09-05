class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        vector<int>::iterator low;
        for(vector<int>::iterator it=numbers.begin(); it < numbers.end(); ++it){
            int n = *it;
            int r = target - n;
            // cout<<n<<" "<<r<<endl;
            if(it + 1 < numbers.end())
                low = lower_bound(it + 1, numbers.end(), r);
            else
                continue;
            if(low == numbers.end())
                continue;
            // cout<<"low:"<<*low<<endl;
            if(*low == r){
                ans.push_back(it - numbers.begin() + 1);
                ans.push_back(low - numbers.begin() + 1);
            }
            
        }
        return ans;
    }
};