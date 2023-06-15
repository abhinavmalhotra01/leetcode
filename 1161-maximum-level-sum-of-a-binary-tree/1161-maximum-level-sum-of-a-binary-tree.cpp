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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int sum =INT_MIN;
        int i=0,out=0;
        while(!q.empty()){
            int k = q.size();
            int currS =0;
            i++;
            while(k--){
                TreeNode* curr = q.front();
                q.pop();
                currS+= curr->val;
                if(curr->left){q.push(curr->left);}
                if(curr->right){q.push(curr->right);}
            }
            if(sum<currS){sum=currS;out=i;}
        }
        return out;
    }
};