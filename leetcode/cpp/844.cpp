class Solution {
public:
    string generate(string s){
        stack<char> st;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '#'){
                if(!st.empty())
                    st.pop();
            }else
                st.push(s[i]);
        }
        string gen = "";
        while(!st.empty()){
            gen = st.top() + gen;
            st.pop();
        }
        return gen;
    }
    bool backspaceCompare(string s, string t) {
        string s2 = generate(s);
        string t2 = generate(t);
        return s2 == t2;
    }
};