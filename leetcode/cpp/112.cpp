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
    bool traverseTree(TreeNode* root, int sum, int targetSum){
        if(root == NULL)
            return false;
        if(root->left == NULL && root->right == NULL){
            if(sum + root->val == targetSum){
                return true;
            }else
                return false;
        }
        sum += root->val;
        return traverseTree(root->left, sum, targetSum) || traverseTree(root->right, sum, targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return traverseTree(root, 0, targetSum);
    }
};