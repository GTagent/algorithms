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
    struct node{
        TreeNode* p;
        int row;
        int col;
        node(TreeNode* t, int r, int c){
            p = t;
            row = r;
            col = c;
        }
    };
    static bool comp_node(const node& a, const node & b){
        return (a.col < b.col) || ((a.col == b.col) && (a.row < b.row)) || ((a.col == b.col) && (a.row == b.row) && ((a.p)->val < (b.p)->val));
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        vector<node> arr;
        arr.push_back(node(root, 0, 0));
        for(int i = 0; i < arr.size(); ++i){
            TreeNode* p = arr[i].p;
            int r = arr[i].row;
            int c = arr[i].col;
            if(p->left){
                arr.push_back(node(p->left, r + 1, c - 1));
            }
            if(p->right){
                arr.push_back(node(p->right, r + 1, c + 1));
            }
        }
        sort(arr.begin(), arr.end(), comp_node);
        int col = arr[0].col;
        vector<int> t;
        t.push_back((arr[0].p)->val);
        for(int i = 1; i < arr.size(); ++i){
            if(col != arr[i].col){
                ans.push_back(t);
                t.clear();
                col = arr[i].col;
            }
            t.push_back((arr[i].p)->val);
        }
        if(!t.empty()){
            ans.push_back(t);
        }
        return ans;
    }
};