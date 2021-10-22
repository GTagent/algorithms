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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int left = minDepth(root -> left);
        int right = minDepth(root -> right);
        // cout<<root->val<<" "<<left<<" "<<right<<" "<<(left ^ right)<<endl;
        
        if((left > 0) ^ (right > 0))
            return left * (left > 0) + right * (right > 0) + 1;
        else
            return min(left, right) + 1;
    }
};