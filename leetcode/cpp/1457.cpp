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
    bool isPalin(vector<int>& hash){
        int k = 0;
        for(int i = 1; i < 10; ++i){
            if((hash[i] & 1) != 0){
                ++k;
            }
        }
        if(k > 1)
            return false;
        else
            return true;
    }
    int checkPalin(TreeNode* p, vector<int>& hash){
        if(!p)
            return 0;
        ++hash[p->val];
        int val = 0;
        if(p->left)
            val += checkPalin(p->left, hash);
        if(p->right)
            val += checkPalin(p->right, hash);
        if(!p->left && !p->right){
            val += isPalin(hash);
        }
        --hash[p->val];
        return val;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> hash(10, 0);
        return checkPalin(root, hash);
    }
};