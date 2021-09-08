class Solution {
public:
    int calcHappy(int n){
        int sum = 0;
        while(n){
            int d = n % 10;
            n /= 10;
            sum += d * d;
        }
        return sum;
    }
    bool isHappy(int n) {
        map<int, int> m;
        m[n] = 1;
        while(n){
            // cout<<n<<" "<<calcHappy(n)<<endl;
            n = calcHappy(n);  
            if(n == 1)
                return true;
            map<int, int>::iterator it = m.find(n);
            if(it != m.end())
                return false;
            m[n] = 1;
        }
        return false;
    }
};