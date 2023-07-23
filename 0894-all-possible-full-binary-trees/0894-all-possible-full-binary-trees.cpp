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
    // TreeNode* root;
    // vector<TreeNode*> out;
    // void rec(int n,TreeNode* cur){
    //     if(n==0){out.push_back(root);return;}
    //     if(n<0){return;}
    //     cur->left = new TreeNode(0);
    //     cur->right = new TreeNode(0);
    //     rec(n-2,cur->left);rec(n-2,cur->right);
    //     cur->left = NULL;
    //     cur->right=NULL;
    // }
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0) return {};
        if(n==1){
            TreeNode*root=new TreeNode(0);
            return {root};
        }
        vector<TreeNode*>out;
        for(int i=1;i<n;i+=2){
            vector<TreeNode*>lr=allPossibleFBT(i);
            vector<TreeNode*>rr=allPossibleFBT(n-i-1);
            for(auto l:lr){
                for(auto r:rr){
                    TreeNode*root=new TreeNode(0,l,r);
                    out.push_back(root);
                }
            }
        }
        return out;
    }
};