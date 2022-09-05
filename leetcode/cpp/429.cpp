/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/



class Solution {
public:
    
    struct qNode{
        public:
            Node* p;
            int level;

            qNode(Node* _p, int _level){
                p = _p;
                level = _level;
            }
    };
    
    vector<vector<int>> levelOrder(Node* root) {
        if(!root){
            return vector<vector<int>>{};
        }
        vector<vector<int>> ans;
        vector<int> tmp;
        int lvl = 0;
        queue<qNode> q;
        q.push(qNode(root, 1));
        while(!q.empty()){
            qNode t = q.front();q.pop();
            int l = t.level;
            Node* p = t.p;
            if(lvl < l){
                if(lvl != 0){
                    ans.push_back(tmp);
                    tmp.clear();
                }
                lvl = l;
            }
            tmp.push_back(p->val);
            for(Node* c : p->children){
                q.push(qNode(c, l + 1));
            }
        }
        if(!tmp.empty())
            ans.push_back(tmp);
        return ans;
    }
};