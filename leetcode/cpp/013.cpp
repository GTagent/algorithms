class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m{{'I', 1},{'V', 5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int ans = 0;
        int i = 0;
        while (i < s.size()){
            if(s[i] == 'I'){
                if(i + 1 < s.size() && s[i+1] == 'V'){
                    ans += 4; ++i;
                }else if(i + 1 < s.size() && s[i+1] == 'X'){
                    ans += 9; ++i;
                }else
                    ans += m[s[i]];
            }else if (s[i] == 'X'){
                if(i + 1 < s.size() && s[i+1] == 'L'){
                    ans += 40; ++i;
                }else if(i + 1 < s.size() && s[i+1] == 'C'){
                    ans += 90; ++i;
                }else
                    ans += m[s[i]];
            }else if (s[i] == 'C'){
                if(i + 1 < s.size() && s[i+1] == 'D'){
                    ans += 400; ++i;
                }else if(i + 1 < s.size() && s[i+1] == 'M'){
                    ans += 900; ++i;
                }else
                    ans += m[s[i]];
            }else
                ans += m[s[i]];
            ++i;
        }
        return ans;
    }
};