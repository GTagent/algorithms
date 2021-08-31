class Solution {
public:
    bool isAlphaNumeric(char c){
        if(((c >= 'A') && (c <= 'Z'))||((c >= 'a') && (c <= 'z'))||(c >= '0' && c <= '9'))
            return true;
        else
            return false;
    }
    char getLower(char c){
        if(c >= 'A' && c <= 'Z')
            return c - 'A' + 'a';
        else
            return c;
    }
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j){
            while(i < j && (!isAlphaNumeric(s[i]))) ++i;
            while(i < j && (!isAlphaNumeric(s[j]))) --j;
            if(i >= j)
                break;
            s[i] = getLower(s[i]);
            s[j] = getLower(s[j]);
            if(s[i] != s[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
};