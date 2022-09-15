class Solution {
public:
    int byte5 = (1 << 7) + (1 << 6) + (1 << 5) + (1 << 4) + (1 << 3);
    int byte4 = (1 << 7) + (1 << 6) + (1 << 5) + (1 << 4);
    int byte3 = (1 << 7) + (1 << 6) + (1 << 5);
    int byte2 = (1 << 7) + (1 << 6);
    int byte1 = (1 << 7);
    
    int checkFst(int k){
        if(((k ^ byte4) & byte5) == 0)
            return 4;
        if(((k ^ byte3) & byte4) == 0)
            return 3;
        if(((k ^ byte2) & byte3) == 0)
            return 2;
        if((k & byte1) == 0)
            return 1;
        // if(((k & byte4) == byte4) && ((k & (1 << 3)) == 0)){
        //     return 4;
        // }
        // if(((k & byte3) == byte3) && ((k & (1 << 4)) == 0))
        //     return 3;
        // if(((k & byte2) == byte2) && ((k & (1 << 5)) == 0))
        //     return 2;
        // if((k & byte1) == 0)
        //     return 1;
        return -1;
    }
    
    bool validUtf8(vector<int>& data) {
        int idx = 0;
        while(idx < data.size()){
            int k = checkFst(data[idx]);
            if(k == -1)
                return false;
            if(idx + k - 1 >= data.size())
                return false;
            // cout<<idx<<":"<<data[idx]<<" "<<k<<endl;
            for(int j = 0; j < k - 1; ++j){
                ++idx;
                // cout<<idx<<":"<<data[idx]<<" "<<(data[idx] ^ byte1)<<" "<<((data[idx]^byte1)&byte2)<<";"<<(data[idx] & byte1)<<" "<<(data[idx] & byte2)<<endl;
                if(((data[idx] ^ byte1)& byte2) != 0)
                    return false;
            }
            ++idx;
        }
        return true;
    }
};