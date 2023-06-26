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
    int l=0,r=0;
    int heightL(TreeNode* root){
        if(!root){return 0;}
        if(root->left){
            return heightL(root->left)+1;
        }
        return 1;
    }
    int heightR(TreeNode* root){
        if(!root){return 0;}
        if(root->right){
            return heightR(root->right)+1;
        }
        return 1;
    }
public:
    int countNodes(TreeNode* root) {
        int l=heightL(root);
        int r=heightR(root);
        if(l==r){
            return pow(2,l)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};