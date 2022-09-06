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
public:
    bool prune(TreeNode* p){
        if(!p){
            return false;
        }
        bool flag = (p->val == 1);
        if(p->left){
            if(!prune(p->left)){
                p->left = NULL;
            }else{
                flag = true;
            }
        }
        if(p->right){
            if(!prune(p->right)){
                p->right = NULL;
            }else{
                flag = true;
            }
        }
        return flag;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(prune(root))
            return root;
        else
            return NULL;
    }
};