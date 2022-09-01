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
    int countGoodNodes(TreeNode* p, int maxNum){
        int num = (p->val >= maxNum);
        if(p->left){
            num += countGoodNodes(p->left, max(maxNum, p->val));
        }
        if(p->right){
            num += countGoodNodes(p->right, max(maxNum, p->val));
        }
        return num;
    }
    
    int goodNodes(TreeNode* root) {
        return countGoodNodes(root, INT_MIN);
    }
};