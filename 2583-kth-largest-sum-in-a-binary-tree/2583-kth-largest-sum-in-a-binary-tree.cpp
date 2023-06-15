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
    long long kthLargestLevelSum(TreeNode* root, long long k) {
        multiset<long long>m;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            long long n= q.size();
            long long curr=0;
            while(n--){
                TreeNode* cur = q.front();
                q.pop();
                curr+= cur->val;
                if(cur->left){q.push(cur->left);}
                if(cur->right){q.push(cur->right);}
            }
            if(m.size()<k){m.insert(curr);}
            else if(curr> *m.begin()){
                m.erase(m.begin());
                m.insert(curr);
            }
        }
        if(m.size()<k){return -1;}
        return *m.begin();
    }
};