class Solution {
public:
    vector<vector<string>> generateLevel(int level){
        if(level < 1){
            return vector<vector<string>>{};
        }
        if(level == 1){
            return vector<vector<string>>{{"()"}};
        }
        vector<vector<string>> sub;
        vector<string> cur;
        sub = generateLevel(level - 1);
        map<string, int> hash;
        // 1 + (level - 1)
        for(int i = 0; i < sub[level - 2].size(); ++i){
            string s1 = "()" + sub[level - 2][i];
            string s2 = sub[level - 2][i] + "()";
            string s3 = "(" + sub[level - 2][i] + ")";
            if (hash.find(s1) == hash.end()){
                hash[s1] = 1;
                cur.push_back(s1);
            }
            if (hash.find(s2) == hash.end()){
                hash[s2] = 1;
                cur.push_back(s2);
            }
            if (hash.find(s3) == hash.end()){
                hash[s3] = 1;
                cur.push_back(s3);
            }
        }
        // 2, 3, ...
        for(int i  = 2; i <= (level >> 1); ++i){
            int k = level - i;
            if(k < i)
                break;
            for(int l = 0; l < sub[i - 1].size(); ++l){
                for(int h = 0; h < sub[k - 1].size(); ++h){
                    string low = sub[i - 1][l];
                    string high = sub[k - 1][h];
                    string s1 = low + high;
                    string s2 = high + low;
                    // cout<<i<<" "<<sub[i - 1].size()<<" "<<l<<" "<<k<<" "<<sub[k - 1].size()<<" "<<h<<" "<<low<<" "<<high<<" "<<s1<<" "<<s2<<endl;
                    if(hash.find(s1) == hash.end()){
                        hash[s1] = 1;
                        cur.push_back(s1);
                    }
                    if(hash.find(s2) == hash.end()){
                        hash[s2] = 1;
                        cur.push_back(s2);
                    }
                }
            }
        }
        sub.push_back(cur);
        return sub;     
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans = generateLevel(n)[n - 1];
        sort(ans.begin(), ans.end());
        return ans;
    }
};