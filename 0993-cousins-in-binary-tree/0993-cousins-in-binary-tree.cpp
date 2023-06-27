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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int c=q.size();
            set<int> s;
            while(c--){
                TreeNode* curr=q.front();
                q.pop();
                if(!curr){continue;}
                s.insert(curr->val);
                if(curr->left && curr->left->val==x && curr->right && curr->right->val==y){
                    return false;
                }
                if(curr->left && curr->left->val==y && curr->right && curr->right->val==x){
                    return false;
                }
                q.push(curr->left);
                q.push(curr->right);
            }
            if(s.count(x) && s.count(y)){
                return true;
            }
        }
        return false;
    }
};