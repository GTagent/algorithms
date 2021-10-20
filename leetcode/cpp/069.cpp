class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) return x;
        int l = 1;
        int r = x;
        int ans = 0;
        while(l <= r){
            int mid = l + ((r - l) >> 1);
            cout<<l<<" "<<r<<" "<<mid<<" "<<ans<<" "<<x<<endl;
            if(mid <= (x/mid)){
                ans = mid;
                l = mid + 1;
            }else
                r = mid -1;
        }
        return ans;
    }
};