/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
        vector<TreeNode*> nodes;
public:
    bool isSubtree(TreeNode* r, TreeNode* s) {
        if(!r && !s) return true;
        if(!r || ! s) return false;
        
        getDepth(r, getDepth(s, -1));
        
        for(TreeNode * n : nodes){
            if(identical(n, s))
                return true;
        }
        return false;
    }
    int getDepth(TreeNode* p, int d){
        if(!p)
            return -1;
        int depth = max(getDepth(p->left, d), getDepth(p->right, d)) + 1;
        if(depth == d)
            nodes.push_back(p);
        return depth;
    }
    bool identical(TreeNode * t, TreeNode * s){
        if(!t && !s) return true;
        if(!t || !s) return false;
        return (t->val == s->val) and identical(t->left, s->left) and identical(t->right, s->right);
    }
};