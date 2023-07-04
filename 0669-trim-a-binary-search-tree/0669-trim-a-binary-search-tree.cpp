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
    TreeNode* rec(TreeNode* root , int low , int high ){
        if(!root){return NULL;}
        if(root->val < low){
            // cout<<root->val;
            root=rec(root->right,low,high);
            // if(root){cout<<root->val;}
        }
        else if(root->val >high){
            root=rec(root->left,low,high);
        }
        else{
            root->left = rec(root->left,low,high);
            root->right = rec(root->right,low,high);
        }
        return root;
    }
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return rec(root,low,high);
    }
};