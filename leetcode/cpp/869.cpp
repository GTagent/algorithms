class Solution {
public:
    map<int, int> getHash(int n){
        map<int, int> hash;
        while(n > 0){
            int k = n % 10;
            n /= 10;
            if(hash.find(k) == hash.end())
                hash[k] = 1;
            else
                hash[k]++;
        }    
        return hash;
    }
    
    bool isEqualMap(map<int,int>& h1, map<int, int>& h2){
        if(h1.size() != h2.size()) return false;
        for(auto iter: h1){
            int key =  iter.first;
            int num = iter.second;
            if(h2.find(key) == h2.end())
                return false;
            if(h2[key] != num)
                return false;
        }
        return true;
    }
    
    void printMap(map<int, int>& h){
        cout<<h.size()<<" ";
        for(auto iter: h){
            cout<<"("<<iter.first<<":"<<iter.second<<")";
        }
        cout<<endl;
    }
    
    bool reorderedPowerOf2(int n) {
        map<int, int> hash;
        hash = getHash(n);
        int64_t maxint = (int64_t)1<<31;
        int64_t num = 1;
        // printMap(hash);
        // cout<<maxint<<endl;
        while(num < maxint){
            map<int, int> h = getHash(num);
            // cout<<num<<endl;
            // printMap(h);
            if(isEqualMap(hash, h))
                return true;
            num = num << 1;
        }
        return false;
    }
};