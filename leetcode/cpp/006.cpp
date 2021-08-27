class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        int sub=2*numRows-2;
        string ans="";
        for(int i=0;i<numRows;++i){
            int subs[2];
            subs[0]=sub-2*i;
            subs[1]=2*i;
            int j=i;
            int k=0;
            while(j<s.size()){
                ans+=s[j];
                if(subs[k]==0){
                    k=1-k;
                }
                j+=subs[k];
                k=1-k;
            }
        }
        return ans;
    }
};