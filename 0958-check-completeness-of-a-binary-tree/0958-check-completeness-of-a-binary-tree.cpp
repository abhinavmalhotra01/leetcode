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
    // bool rec (TreeNode* root){
    //     if(!root){return true;}
    //     if(root->right){
    //         if(!root->left){
    //             return false;
    //         }
    //     }
    //     if(root->left){
    //         if(root->left->left){
    //             if(!root->right){
    //                 return false;
    //             }
    //         }
    //     }
    //     if(root->left && root->right){
    //         return rec(root->left) && rec(root->right);
    //     }else if(root->left){
    //         return rec(root->left);
    //     }else if(root->right){
    //         return false;
    //     }
    //     return 1;
    // }
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int k=-1;
        while(q.size()){
            int c = q.size();
            vector<TreeNode*> v;
            while(c--){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left){q.push(curr->left);}
                if(curr->right){q.push(curr->right);}
                v.push_back(curr);
            }
            
            for(int i=0;i<v.size();i++){
                if(v[i]->left && k!=-1){return 0;}
                if(v[i]->right && k!=-1){return 0;}
                if(!v[i]->left){
                    if(v[i]->right){return 0;}
                    else{
                        k=i;
                    }
                }
                else if(!v[i]->right){
                    // cout<<v[i]->val;
                    k=i;

                    // return 0;
                }
                // // else{
                //     cout<<v[i]->val<<" "<<k<<endl;
                // }
            }            
        }
        return 1;
    }
};