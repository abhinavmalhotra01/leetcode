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
        queue<Node*> q;
        q.push(root);
        while(q.size()){
            int c=q.size();
            vector<Node*> v;
            while(c--){
                Node* curr=q.front();
                q.pop();
                if(!curr){continue;}
                v.push_back(curr);
                q.push(curr->left);
                q.push(curr->right);
            }
            if(!v.size()){continue;}
            for(int i=0;i<v.size()-1;i++){
                v[i]->next =  v[i+1];
            }
            v[v.size()-1]->next=NULL;
        }
        return root;
    }
};