class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        bool flag = true;
        for(int i = 30; i >= 0; --i){
            int bit = 1 << i;
            // cout<<bit<<" "<<(bit & right)<<" "<<(bit & left)<<endl;
            if((bit & left) == (bit & right)){
                ans += (bit & left);
                flag = false;
            }else{
                if(((bit & right) ^ (bit & left)) || (!flag))
                    break;
                // if((bit & right) && (!(bit & left)))
                //     break;
            }
        }
        return ans;
    }
};