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
    void post(TreeNode* p, vector<int>& ans){
        if(!p)
            return;
        post(p->left, ans);
        post(p->right, ans);
        ans.push_back(p->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        post(root, ans);
        return ans;
    }
};