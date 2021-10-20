class Solution {
public:
    // kmp algorithm
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        // if(haystack == "") return 0;
        vector<int> nxt(needle.size() + 10);
        vector<int> s(haystack.size() + 10);
        
        // build nxt array
        int now = 0, x = 1;
        nxt[0] = 0;
        while(x < needle.size()){
            if(needle[x] == needle[now]){
                nxt[x++] = ++now;
            }else{
                if(now){
                    now = nxt[now - 1];
                }else{
                    nxt[x++] = 0;
                }
            }
        }
        
        // start compare
        now = 0;
        x = 0;
        while(x < haystack.size()){
            if(haystack[x] == needle[now]){
                ++x;++now;
            }else if(now){
                now = nxt[now - 1];
            }else
                ++x;
            if(now == needle.size()){
                // cout<<x<<" "<<now<<endl;
                return x - now;
            }
        }
        return -1;
    }
};