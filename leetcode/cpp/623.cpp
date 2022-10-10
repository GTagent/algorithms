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
    void addRowEle(TreeNode* p,int val, int depth, int d){
        if(!p)
            return;
        if(d == depth - 1){
            TreeNode* left = new TreeNode(val, p->left, NULL);
            TreeNode* right = new TreeNode(val, NULL, p->right);
            p->left = left;
            p->right = right;
            return;
        }
        addRowEle(p->left, val, depth, d + 1);
        addRowEle(p->right, val, depth, d + 1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* p = new TreeNode(val, root, NULL);
            return p;
        }
        addRowEle(root, val, depth, 1);
        return root;
    }
};