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
    bool out=true;
    int height(TreeNode* root){
        if(!root){return 0;}
        int hl=height(root->left);
        int hr=height(root->right);
        if(abs(hl-hr)>1){
            out=false;
        }
        return max(hl,hr)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        height(root);
        return out;
    }
};