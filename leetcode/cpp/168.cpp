class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        int x = columnNumber;
        while(x){
            x--;
            int r = x % 26;
            ans += (char)('A' + r);
            x /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};