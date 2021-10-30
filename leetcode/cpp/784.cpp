class Solution {
public:
    bool isDigit(char c){
        return c >= '0' && c <= '9';
    }
    bool isLetter(char c){
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
    }
    char toLower(char c){
        if(!isLetter(c))
            return c;
        if(c >= 'A' && c <= 'Z')
            return (char)(c - 'A' + 'a');
        else
            return c;
    }
    char toUpper(char c){
        if(!isLetter(c))
            return c;
        if(c >= 'a' && c <= 'z')
            return (char)(c - 'a' + 'A');
        else
            return c;
    }
    void generate(string& s, int index, vector<string>& ans){
        if(index >= s.size()){
            ans.push_back(s);
            return;
        }
        int i = index;
        while(i < s.size() && isDigit(s[i])) ++i;
        if(i < s.size()){
            char c = s[i];
            // cout<<c<<" "<<toLower(c)<<" "<<toUpper(c)<<endl;
            s[i] = toLower(c);
            generate(s, i + 1, ans);
            s[i] = toUpper(c);
            generate(s, i + 1, ans);
        }else
            generate(s, index + 1, ans);
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        generate(s, 0, ans);
        return ans;
    }
};