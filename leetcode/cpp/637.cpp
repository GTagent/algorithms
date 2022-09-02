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
    struct qNode{
        TreeNode* node;
        int level;
    };
    
    qNode consNode(TreeNode* p, int level){
        qNode t;
        t.node = p;
        t.level = level;
        return t;
    }
    vector<double> averageOfLevels(TreeNode* root) {
        queue<qNode> q;
        while(!q.empty())q.pop();
        q.push(consNode(root, 1));
        int curLevel = 0;
        int curNum = 0;
        double curAvg = 0;
        vector<double> ans;
        while(!q.empty()){
            qNode t = q.front();q.pop();
            TreeNode* p = t.node;
            int l = t.level;
            if(l != curLevel){
                curLevel = l;
                if (curNum){
                    curAvg = curAvg / curNum;
                    ans.push_back(curAvg);
                }
                curAvg = 0;
                curNum = 0;
            }
            ++curNum;
            curAvg = curAvg + p->val;
            if(p->left){
                q.push(consNode(p->left, l + 1));
            }
            if(p->right){
                q.push(consNode(p->right, l + 1));
            }
        }
        if(curNum){
            curAvg = curAvg / curNum;
            ans.push_back(curAvg);
        }
        return ans;
    }
};