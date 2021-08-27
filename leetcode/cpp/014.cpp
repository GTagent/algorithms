class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int hash[200][30];
        int maxlen = 0;
        memset(hash, 0, sizeof(hash));
        for(int i = 0; i < strs.size(); ++i){
            string s = strs[i];
            for(int j = 0; j < s.size(); ++j){
                ++hash[j][s[j]-'a'];
            }
            if(s.size()>maxlen)
                maxlen = s.size();
        }
        // cout<<hash[0]['f'-'a']<<" "<<strs.size()<<endl;
        string ans = "";
        for(int i = 0;i < maxlen; ++i){
            bool flag = false;
            for(int j = 0; j < 26; ++j){
                if(hash[i][j] == strs.size()){
                    ans += ('a'+j);
                    flag = true;
                }
            }
            if(not flag)
                break;
        }
        return ans;
    }
};