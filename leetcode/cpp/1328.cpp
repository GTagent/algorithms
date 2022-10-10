class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n == 1)
            return "";
        bool smaller = false;
        for(int i = 0; i < (n >> 1); ++i){
            if(palindrome[i] > 'a'){
                smaller = true;
                palindrome[i] = 'a';
                break;
            }
        }
        if(!smaller){
            palindrome[n - 1] = (char)(palindrome[n - 1] + 1);
        }
        return palindrome;
    }
};