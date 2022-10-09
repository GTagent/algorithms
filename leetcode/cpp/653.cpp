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
    map<int, int> hash;
    void traverse(TreeNode* p){
        if(!p)
            return;
        ++hash[p->val];
        traverse(p->left);
        traverse(p->right);
    }
    bool findTarget(TreeNode* root, int k) {
        hash.clear();
        traverse(root);
        for(auto iter: hash){
            int v = iter.first;
            // cout<<k<<":"<<v<<" "<<hash[v]<<" "<<k - v<<" "<<hash[k - v]<<endl;
            if(k - v == v){
                if(iter.second > 2)
                    return true;
                else
                    return false;
            }else{
                if(hash.find(k - v) != hash.end() && hash[k - v] > 0)
                    return true;
            }
        }
        return false;
    }
};