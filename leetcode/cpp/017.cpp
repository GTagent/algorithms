class Solution {
public:
    map<int, string> m{{2,"abc"}, {3, "def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
    void generateStr(vector<string>& ans, string& digits, int index, string str){
        // cout<<index<<" "<<digits[index]<<" "<<str<<" "<<ans.size()<<endl;
        if(index >= digits.size()){
            if(str != "")
                ans.push_back(str);
            return;
        }
        int n = digits[index] - '0';
        string sdigits = m[n];
        for(int i = 0; i < sdigits.size(); ++i){
            generateStr(ans, digits, index + 1, str + sdigits[i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        generateStr(ans, digits, 0, "");
        return ans;
    }
};