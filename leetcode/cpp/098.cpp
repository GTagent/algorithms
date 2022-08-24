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
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true;
        if(root->left != NULL){
            TreeNode* p = root->left;
            while(p->right != NULL) p = p->right;
            if (!(p->val < root->val && isValidBST(root->left)))
                return false;
        }
        if(root->right != NULL){
            TreeNode* p = root->right;
            while(p->left != NULL) p = p->left;
            if(!(p->val > root->val && isValidBST(root->right)))
                return false;
        }
        return true;
    }
};