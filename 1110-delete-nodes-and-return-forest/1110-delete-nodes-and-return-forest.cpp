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
    TreeNode* rec(TreeNode*root ,set<int>& s,vector<TreeNode*>& out){
        if(!root){
            // cout
            // out.push_back(parent);
            return NULL;
        }
        root->left = rec(root->left,s,out);
        root->right = rec(root->right,s,out);
        if(s.count(root->val)){
            if(root->left){
                out.push_back(root->left);
            }
            if(root->right){
                out.push_back(root->right);
            }
            return NULL;
        }
        return root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> out;
        set<int> s;
        for(auto e:to_delete){
            s.insert(e);
        }
        TreeNode*f = rec(root,s,out);
        if(f){out.push_back(f);}
        return out;
    }
};