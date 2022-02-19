class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string ans = "";
        int p = 0;
        for(int i = 0; i < max(num1.size(), num2.size()); ++i){
            int d = p;
            if(i < num1.size()){
                d += num1[i] - '0';
            }
            if(i < num2.size()){
                d += num2[i] - '0';
            }
            if(d >= 10){
                d -= 10;
                p = 1;
            }else
                p = 0;
            ans += (char)('0' + d);
        }
        if(p) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};