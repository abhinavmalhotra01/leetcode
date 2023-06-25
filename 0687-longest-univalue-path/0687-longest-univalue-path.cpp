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
    int out=0;
    int rec(TreeNode*root){
        if(!root){return 0;}
        int l=0,r=0;
        if(root->left){
            int l2=rec(root->left);
            if(root->left->val==root->val){l=l2;}
        }
        if(root->right){
            int r2=rec(root->right);
            if(root->right->val == root->val){r=r2;}
        }
        int curr = (l+r)+1;
        // cout<<root->val<<" "<<curr<<endl;
        // cout<<c<<endl;
        out=max(out,curr);
        // cout<<out<<endl;
        // if(curr>out){
        //     // cnt=c;
        //     out=curr;
        // }
        return max(l,r)+1;
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        rec(root);
        if(!out){return out;}
        return out-1;
    }
};