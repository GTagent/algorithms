class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> hash1, hash2;
        for(char c: ransomNote){
            if(hash1.find(c) == hash1.end()){
                hash1[c] = 1;
            }else
                ++hash1[c];
        }
        for(char c: magazine){
            if(hash2.find(c) == hash2.end()){
                hash2[c] = 1;
            }else
                ++hash2[c];
        }
        for(auto iter: hash1){
            char c = iter.first;
            int n = iter.second;
            if(hash2.find(c) == hash2.end() || hash2[c] < n)
                return false;
        }
        return true;
    }
};