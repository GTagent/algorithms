class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        while(!st.empty()) st.pop();
        // cout<<"yes?"<<endl;
        for(int i = 0; i < s.size(); ++i){
            // cout<<i<<" "<<s[i]<<" "<<st.size()<<endl;
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else if(s[i] ==')'){
                if(st.empty() || st.top() != '(')
                    return false;
                st.pop();
            }else if(st.empty() || s[i] == ']'){
                if(st.empty() || st.top() != '[')
                    return false;
                st.pop();
            }else if(st.empty() || s[i] == '}'){
                if(st.top() != '{')
                    return false;
                st.pop();
            }
        }
        // cout<<"ok?"<<endl;
        if(!st.empty())
            return false;
        return true;
    }
};