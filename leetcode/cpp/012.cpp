class Solution {
public:
    string intToRoman(int num) {
        map<int, string> m{{1000, "M"},{900,"CM"},{500, "D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}};
        string s = "";
        for(map<int,string>::reverse_iterator it=m.rbegin();it != m.rend();++it){
            int key = it->first;
            string str = it->second;
            // cout<<key<<" "<<str<<endl;
            while(num >= key){
                num -= key;
                s += str;
            }
        }
        return s;
    }
};