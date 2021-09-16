// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        uint32_t l = 1, r = n;
        while(l < r){
            uint32_t m = uint32_t(l + r) >> 1;
            if(isBadVersion(m)){
                r = m;
            }else{
                l = m + 1;
            }
        }
        return l;
    }
};