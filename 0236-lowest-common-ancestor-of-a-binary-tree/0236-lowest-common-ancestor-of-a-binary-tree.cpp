/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* rec(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root || root==p || root==q){
            return root;
        }
        TreeNode* l =rec(root->left,p,q);
        TreeNode* r =rec(root->right,p,q);
        if(!l){return r;}
        if(!r){return l;}
        return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return rec(root,p,q);
    }
};