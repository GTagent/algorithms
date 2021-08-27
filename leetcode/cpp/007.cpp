class Solution {
public:
    int reverse(int x) {
        bool negative{false};
        long long y=x;
        if(y<0){
            negative=true;
            y=-y;
        }
        long long ans=0;
        while(y>0){
            ans=(long long)((long long)(ans*10)+(y%10));
            y=y/10;
        }
        if(negative){
            ans=-ans;
        }
        if(ans<INT_MIN || ans>INT_MAX)
            return 0;
        else
            return ans;
    }
};