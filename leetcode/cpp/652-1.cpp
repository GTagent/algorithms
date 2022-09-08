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
    map<string, int> hash;
    vector<TreeNode*> ans;
    
    string genStruct(TreeNode* p){
        if(!p)
            return "N";
        string s = to_string(p->val);
        s += "(" + genStruct(p->left) + ")(" + genStruct(p->right) + ")";
        if(hash.find(s) == hash.end())
            hash[s] = 1;
        else{
            if(hash[s] == 1){
                ans.push_back(p);
                hash[s] = 2;
            }
        }
        return s;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        hash.clear();
        ans.clear();
        genStruct(root);
        return ans;
    }
};