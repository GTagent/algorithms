class Solution {
public:
    int numDecodings(string s) {
        vector<int> f(s.size() + 10);
        f[0] = 1;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '0'){
                if(i == 0 || s[i - 1] > '2')
                    return 0;
                f[i + 1] = f[i - 1];
            }else{
                if(i + 1 < s.size() && s[i + 1] == '0'){
                    f[i + 1] = 0;
                    continue;
                }
                if(i > 0 && s[i - 1] != '0'){
                    int num = (s[i] - '0') + (s[i - 1] - '0') * 10;
                    // cout<<s[i - 1]<<s[i]<<" "<<num<<endl;
                    if(num >= 1 && num <= 26){
                        f[i + 1] = f[i] + f[i - 1];
                        continue;
                    }
                }
                f[i + 1] = f[i];
            }
        }
        return f[s.size()];
    }
};