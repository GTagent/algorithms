class Solution {
public:
    int myAtoi(string str) {
        string num="";
        bool bFind=false;
        bool bNum=false;
        bool bNeg=false;
        for(int i=0;i<str.size();++i){
            if(str[i]==' ' && !bFind){
                continue;
            }
            if(str[i]=='-' || str[i]=='+'){
                if(bFind)
                    break;
                bFind=true;
                if(str[i]=='+')
                    continue;
                if(str[i]=='-')
                    bNeg=true;
            }else if(str[i]>='0' && str[i]<='9'){
                num+=str[i];
                bFind=true;
                bNum=true;
            }else break;
        }
        if(!bNum)
            return 0;
        long long ans=0;
        for(int i=0;i<num.size();++i){
            ans=ans*10+num[i]-'0';
            if(ans>INT_MAX)
                break;
        }
        if(!bNeg && ans>INT_MAX)
            return INT_MAX;
        else if (bNeg && ans>(-(long)INT_MIN))
            return INT_MIN;
        else
            return bNeg? -ans:ans;
    }
};