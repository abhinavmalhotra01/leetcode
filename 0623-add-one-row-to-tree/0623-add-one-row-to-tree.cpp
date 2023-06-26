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
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newR = new TreeNode(val);
            newR->left=root;
            return newR;
        }
        depth--;
        depth--;
        queue<TreeNode*> q;
        q.push(root);
        int i=0;
        while(q.size()){
            if(i==depth){
                int curr=q.size();
                while(curr--){
                    TreeNode* curN = q.front();
                    q.pop();
                    // cout<<curN->val<<endl;
                    if(!curN){continue;}
                    TreeNode* oe = new TreeNode(val);
                    TreeNode* l = curN->left;
                    TreeNode* r = curN->right;
                    oe->left = l;
                    curN->left=oe;
                    TreeNode* oe2 = new TreeNode(val);
                    oe2->right=r;
                    curN->right=oe2;
                }
                return root;
            }else{
                int curr=q.size();
                while(curr--){
                    TreeNode* curN = q.front();
                    q.pop();
                    if(!curN){continue;}
                    q.push(curN->left);
                    q.push(curN->right);
                }
            }
            i++;
        }
        return root;
    }
};