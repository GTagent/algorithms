class Solution {
public:
    unordered_map<string, int> hash;
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
        genStruct(root);
        return ans;
    }
};