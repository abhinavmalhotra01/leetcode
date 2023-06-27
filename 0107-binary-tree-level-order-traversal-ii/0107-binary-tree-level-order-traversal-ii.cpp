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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> out;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int c = q.size();
            vector<int> cur;
            while(c--){
                TreeNode*curr=q.front();
                q.pop();
                if(!curr){continue;}
                cur.push_back(curr->val);
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            if(!cur.size()){continue;}
            out.push_back(cur);
        }
        reverse(out.begin(),out.end());
        return out;
    }
};