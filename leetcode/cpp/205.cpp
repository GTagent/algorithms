class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> m;
        map<char, char> h;
        for(int i = 0; i < s.size(); ++i){
            char cs = s[i], ct = t[i];
            if(m.find(cs) == m.end()){
                m[cs] = ct;
            }else{
                if(m[cs] != ct)
                    return false;
            }
            if(h.find(ct) == h.end()){
                h[ct] = cs;
            }else{
                if(h[ct] != cs)
                    return false;
            }
        }
        return true;
    }
};