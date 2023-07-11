/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void parents(TreeNode* root,map<TreeNode*,TreeNode*>& m,TreeNode* t){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left){
                m[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                m[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> mp;
        parents(root,mp,target);
        map<TreeNode*,bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target]=true;
        int curr=0;
        while(!q.empty()){
            int size = q.size();
            if(curr++ == k){break;}
            for(int i=0;i<size;i++){
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left && !vis[cur->left]){
                    vis[cur->left]=true;
                    q.push(cur->left);
                }
                if(cur->right && !vis[cur->right]){
                    vis[cur->right]=true;
                    q.push(cur->right);
                }
                if(mp[cur] && !vis[mp[cur]]){
                    q.push(mp[cur]);
                    vis[mp[cur]]=true;
                }
            }
        }
        vector<int> out;
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            out.push_back(current->val);
        }
        return out;
    }
};