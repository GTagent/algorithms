class Solution {
public:
    string addBinary(string a, string b) {
        int len = max(a.size(), b.size());
        vector<int> x(len + 10);
        vector<int> y(len + 10);
        for(int i = a.size() - 1, j = 0; i >= 0; --i, ++j)
            x[j] = a[i] - '0';
        for(int i = b.size() - 1, j = 0; i >= 0; --i, ++j)
            y[j] = b[i] - '0';
        vector<int> ans(len + 10);
        for(int i = 0; i <= len; ++i){
            ans[i] += x[i] + y[i];
            if (ans[i] >= 2){
                ++ans[i + 1];
                ans[i] -= 2;
            }
        }
        if (ans[len] > 0) ++len;
        string s = "";
        for(int i = len - 1; i >= 0; --i) s += to_string(ans[i]);
        return s;
    }
};