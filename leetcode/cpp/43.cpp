class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<int> ans(num1.size() + num2.size() + 10);
        for(int i = 0; i < num1.size(); ++i){
            for(int j = 0; j < num2.size(); ++j){
                ans[i + j] += (num1[i] - '0') * (num2[j] - '0');
                if(ans[i + j] >= 10){
                    ans[i + j + 1] += ans[i + j] / 10;
                    ans[i + j] %= 10;
                }
            }
        }
        string ret = "";
        bool flag = true;
        for(int i = num1.size() + num2.size() + 1; i >= 0; --i){
            if(!flag || ans[i] != 0){
                ret += (char)(ans[i] + '0');
                flag = false;
            }
        }
        return flag? "0" : ret;
    }
};