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
    void rec(TreeNode* root , int val){
        if(!root){return;}
        if(root->val < val){
            if(!root->right){
                root->right = new TreeNode(val);
                return;
            }else{
                rec(root->right,val);
            }
        }else{
            if(!root->left){
                root->left=new TreeNode(val);
                return;
            }else{
                rec(root->left,val);
            }
        }
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode* n= new TreeNode(val);
            return n;
        }
        rec(root,val);
        return root;
    }
};