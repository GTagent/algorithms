class Solution {
public:
    struct node{
        int val;
        int l;
        
        node(int n, int len){
            val = n;
            l = len;
        }
    };
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        queue<node> q;
        for(int i = 1; i <= 9; ++i){
            q.push(node(i, 1));
        }
        while(!q.empty()){
            node t = q.front();q.pop();
            int v = t.val;
            int l = t.l;
            int ln = v % 10;
            if(l > n)
                continue;
            if(l == n){
                ans.push_back(v);
                continue;
            }else{
                if(ln + k <= 9){
                    int tv = v * 10 + (ln + k);
                    q.push(node(tv, l + 1));
                }
                if(ln - k >= 0 && k != 0){
                    int tv = v * 10 + (ln - k);
                    q.push(node(tv, l + 1));
                }
            }
        }
        return ans;
    }
};