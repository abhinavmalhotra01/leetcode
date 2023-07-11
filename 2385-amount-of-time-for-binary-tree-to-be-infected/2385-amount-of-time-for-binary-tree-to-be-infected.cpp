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
    void addP(TreeNode* root , map<TreeNode*,TreeNode*>& par){
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int sz = q.size();
            while(sz--){
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left){
                    par.insert({cur->left,cur});
                    q.push(cur->left);
                }
                if(cur->right){
                    par.insert({cur->right,cur});
                    q.push(cur->right);
                }
            }
        }
    }
    TreeNode* find(TreeNode* root,int v){
        if(!root){return NULL;}
        if(root->val == v){
            return root;
        }
        if(root->left){
            TreeNode* l = find(root->left,v);
            if(l){
                return l;
            }
        }
        if(root->right){
            TreeNode* r=find(root->right,v);
            if(r){
                return r;
            }
        }
        return NULL;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> par;
        addP(root,par);
        int out=0;
        queue<TreeNode*> q;
        map<TreeNode*,int> vis;
        TreeNode* s = find(root,start);
        q.push(s);
        vis[s]=1;
        // if(!(root->left) && !(root->right)){
        //     return 0;
        // }

        while(q.size()){
            int sz=q.size();
            out++;
            while(sz--){
                TreeNode* cur=q.front();
                q.pop();
                if(cur->left && !vis[cur->left]){
                    vis[cur->left]=1;
                    q.push(cur->left);
                }
                if(cur->right && !vis[cur->right]){
                    vis[cur->right]=1;
                    q.push(cur->right);
                }
                if(par[cur] && !vis[par[cur]]){
                    vis[par[cur]]=1;
                    q.push(par[cur]);
                }
            }
        }
        return --out;
    }
};