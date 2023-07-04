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
    int cnt=0,out;
    void rec(TreeNode* root ,int k){
        if(!root){return;}
        // if(cnt==k){out=root->val;}
        if(root->left){
            rec(root->left,k);
        }
        cnt++;
        if(cnt==k){out=root->val;}
        if(root->right){
            rec(root->right,k);
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        rec(root,k);
        return out;
    }
};