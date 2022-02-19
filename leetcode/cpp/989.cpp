class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(), num.end());
        vector<int> num2;
        while(k){
            num2.push_back(k % 10);
            k /= 10;
        }
        vector<int> sum;
        int p = 0;
        for(int i = 0; i < max(num.size(), num2.size()); ++i){
            int d = p;
            if(i < num.size())
                d += num[i];
            if(i < num2.size())
                d += num2[i];
            if(d >= 10){
                p = 1;
                d -= 10;
            }else
                p = 0;
            sum.push_back(d);
        }
        if(p) sum.push_back(1);
        reverse(sum.begin(), sum.end());
        return sum;
    }
};