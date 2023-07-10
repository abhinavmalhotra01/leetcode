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
    int out=INT_MAX;
    void rec(TreeNode* root,int d){
        if(!root){
            // out=min(out,d);
            return;
        }
        if(root->left){
            rec(root->left,d+1);
        }
        if(root->right){
            rec(root->right,d+1);
        }
        else if(!(root->left)){out=min(out,d);}
    }
public:
    int minDepth(TreeNode* root) {
        if(!root){return 0;}
        rec(root,1);
        return out;
    }
};