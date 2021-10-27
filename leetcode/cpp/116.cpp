/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        map<Node*, int> level;
        queue<Node*> q, p;
        q.push(root);
        level[root] = 1;
        int l = 0;
        while(!q.empty()){
            ++l;
            while(!p.empty()) p.pop();
            while(!q.empty() && level[q.front()] == l){
                p.push(q.front());
                q.pop();
            }
            Node* a = NULL;
            while(!p.empty()){
                Node* b = p.front();p.pop();
                if(b->left){
                    q.push(b->left);
                    level[b->left] = l + 1;
                }
                if(b->right){
                    q.push(b->right);
                    level[b->right] = l + 1;
                }
                if(a)
                    a->next = b;
                a = b;
            }
        }
        return root;
    }
};