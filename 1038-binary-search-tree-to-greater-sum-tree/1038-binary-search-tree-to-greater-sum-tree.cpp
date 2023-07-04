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
    void rec(TreeNode* &root, int &curr) 
    {
        if(!root) return;
        rec(root -> right, curr);
        root -> val = curr+= root -> val;
        rec(root -> left, curr);
    }
public:
    TreeNode* bstToGst(TreeNode* root) 
    {
        int curr = 0;
        rec(root, curr);
        return root;
    }
};