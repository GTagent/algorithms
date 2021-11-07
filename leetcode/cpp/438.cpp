class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int hashp[256];
        int hashs[256];
        memset(hashp, 0, sizeof(hashp));
        memset(hashs, 0, sizeof(hashs));
        for(int i = 0; i < p.size(); ++i){
            ++hashp[p[i]];
        }
        for(int i = 0; i < s.size(); ++i){
            ++hashs[s[i]];
            if(i >= p.size() - 1){
                bool equal = true;
                for(int j = 0; j < 256; ++j){
                    if(hashp[j] != hashs[j]){
                        equal = false;
                        break;
                    }
                }
                int front = i - p.size() + 1;
                if(equal){
                    ans.push_back(front);
                }
                --hashs[s[front]];
            }
        }
        return ans;
    }
};