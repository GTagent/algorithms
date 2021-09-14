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
    TreeNode* invertSubTree(TreeNode* p){
        if(!p)
            return p;
        // cout<<"first: "<<p->val<<" "<<p->left->val<<" "<<p->right->val<<endl;
        TreeNode* left = invertSubTree(p->left);
        TreeNode* right = invertSubTree(p->right);
        // cout<<"second: "<<p->val<<" "<<p->left->val<<" "<<p->right->val<<endl;
        p->left = right;
        p->right = left;
        return p;
    }
    TreeNode* invertTree(TreeNode* root) {
        // cout<<root->val<<endl;
        return invertSubTree(root);
    }
};