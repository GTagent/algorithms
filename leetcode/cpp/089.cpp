class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> list;
        set<int> hash;
        int num = 0;
        list.push_back(0);
        hash.insert(0);
        for(int i = 0; i < (1 << n); ++i){
            int k = list[num];
            int p = 1;
            // cout<<k<<endl;
            for(int p = 1; p <= (1<<(n -1)); p = p << 1){
                int q = k ^ p;
                // cout<<q<<" ";
                if(hash.find(q) == hash.end()){
                    ++num;
                    list.push_back(q);
                    hash.insert(q);
                    // cout<<endl;
                    break;
                }
            }
        }
        return list;
    }
};