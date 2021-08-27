class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> hash;
        int ans=0;
        for(int i=0, j=0; j<s.size();++j){
            if (hash.find(s[j])!=hash.end()){
                i=max(hash[s[j]]+1,i);
            }
            ans=max(ans,j-i+1);
            hash[s[j]]=j;
        }
        return ans;
    }
};