class Solution {
public:
    int str2int(string str){
        int val = 0;
        int x = 1;
        for(int i = str.size() - 1; i >= 0; --i, x *= 10){
            val += (int)(str[i] - '0') * x;
        }
        return val;
    }
    int calPoints(vector<string>& ops) {
        stack<int> scores;
        for(string op: ops){
            if(op == "C"){
                scores.pop();
            }
            else if(op == "D"){
                int top = scores.top();
                scores.push(top * 2);
            }
            else if(op == "+"){
                int add1 = scores.top(); scores.pop();
                int add2 = scores.top(); scores.pop();
                int add3 = add1 + add2;
                scores.push(add2);
                scores.push(add1);
                scores.push(add3);
            }else{
                string str;
                bool negative = false;
                if(op[0] == '-'){
                    negative = true;
                    str = op.substr(1, op.size() - 1);
                }else
                    str = op;
                // cout<<"----"<<op<<" "<<str<<endl;
                int val = str2int(str);
                if(negative)
                    val = -val;
                scores.push(val);
            }
            // cout<<op<<" "<<scores.top()<<endl;
        }
        int sum = 0;
        while(!scores.empty()){sum += scores.top(); scores.pop();}
        return sum;
    }
};