class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        vector<int> p;
        int j = x;
        while(j > 0){
            p.push_back(j % 10);
            // cout<<j<<j%10<<j/10<<endl;
            j /= 10;
        }
        for(int i=0; i < p.size(); ++i)
            if (p[i] != p[p.size() -i -1])
                return false;
        return true;
    }
};