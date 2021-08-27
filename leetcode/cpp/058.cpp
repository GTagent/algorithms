class Solution {
public:
    int lengthOfLastWord(string s) {
        int maxlen = 0;
        bool flag = true;
        for(int i = s.size() - 1; i >= 0; --i){
            if (((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))){
                ++maxlen;
                flag = false;
            }else if (not flag && s[i] == ' '){
                break;
            }
        }
        return maxlen;
    }
};