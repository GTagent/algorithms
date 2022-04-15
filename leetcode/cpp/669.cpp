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
    TreeNode* trim(TreeNode* p, int low, int high){
        if(!p) return NULL;
        if(p->val < low){
            return trim(p->right, low, high);
        }
        if(p->val > high){
            return trim(p->left, low, high);
        }
        p->left = trim(p->left, low, high);
        p->right = trim(p->right, low, high);
        return p;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return trim(root, low, high);
    }
};