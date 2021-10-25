class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        map<char, int> hash, h;
        for(int i = 0; i < s1.size(); ++i){
            if(h.find(s1[i]) == h.end()){
                h[s1[i]] = 1;
                hash[s1[i]] = 0;
            }else
                h[s1[i]]++;
        }
        for(int i = 0, j = 0; i < s2.size(); ++i){
            // cout<<i<<" "<<s2[i]<<" "<<j<<endl;
            if(h.find(s2[i]) != h.end()){
                ++j;
                ++hash[s2[i]];
                // cout<<">"<<s2[i]<<" "<<j<<" "<<hash[s2[i]]<<" "<<h[s2[i]]<<endl;
                if(j >= s1.size()){
                    bool isEqual = true;
                    for(auto it : h){
                        char k = it.first;
                        int v = it.second;
                        // cout<<"("<<k<<" "<<v<<") "<<hash[k]<<endl;
                        if(hash[k] != v){
                            isEqual = false;
                            break;
                        }
                    }
                    if(isEqual) return true;
                    hash[s2[i + 1 -j]]--;
                    --j;
                }
            }else{
                for(int k = i - j; k < i; ++k){
                    hash[s2[k]]--;
                    // cout<<":"<<k<<" "<<s2[k]<<" "<<hash[s2[k]]<<endl;
                }
                j = 0;
            }
        }
        return false;
    }
};