class Solution {
public:
    string reverseWords(string s) {
        string ans = "", word = "";
        for(int i = s.size() - 1; i >= 0; --i){
            if(s[i] != ' '){
                word += s[i];
            }else{
                ans = " " + word + ans;
                word = "";
            }
        }
        ans = word + ans;
        return ans;
    }
};