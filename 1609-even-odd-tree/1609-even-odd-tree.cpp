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
// class Solution {
// public:
    // bool isEvenOddTree(TreeNode* root) {
    //     int curr =0;
    //     queue<TreeNode*> q;
    //     TreeNode* prev;
    //     q.push(root);
    //     if(root->left){prev=root;}
    //     else{prev=root->right;}
    //     vector<int> lvl;
    //     while(!q.empty()){
    //         TreeNode* cur = q.front();
    //         // cout<<cur->val<<endl;
    //         lvl.push_back(cur->val);
    //         q.pop();
    //         if(curr%2 == (cur->val)%2){
    //             // cout<<cur->val<<" "<<curr<<endl;
    //             return false;
    //         }
    //         if(cur->left){q.push(cur->left);}
    //         if(cur->right){q.push(cur->right);}
    //         TreeNode* nw = q.front();
    //         // cout<<nw->val<<endl;
    //         // cout
    //         if(prev->left == nw){
    //             prev=prev->left;
    //             // cout<<nw->val<<endl;
    //             if(curr%2){
    //                 vector<int> ok = lvl;
    //                 sort(ok.begin(),ok.end());
    //                 if(ok!=lvl){return false;}
    //                 lvl.clear();
    //             }else{
    //                 vector<int> ok = lvl;
    //                 sort(ok.rbegin(),ok.rend());
    //                 if(ok!=lvl){return false;}
    //                 lvl.clear();
    //             }
    //             curr++;
    //             // cout<<curr<<endl;
    //         }else if( prev->right==nw){
    //             prev=prev->right;
    //             // cout<<nw->val<<endl;
    //             if(curr%2){
    //                 vector<int> ok = lvl;
    //                 sort(ok.begin(),ok.end());
    //                 if(ok!=lvl){return false;}
    //                 lvl.clear();
    //             }else{
    //                 vector<int> ok = lvl;
    //                 sort(ok.rbegin(),ok.rend());
    //                 if(ok!=lvl){return false;}
    //                 lvl.clear();
    //             }
    //             curr++;
    //         }
    //     }
    //     return true;
    // }
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        int f = 0; 
        q.push(root);
        while(!q.empty()){
            int x;
            if(f){x=INT_MAX;}
            else{x=INT_MIN;}
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode *temp = q.front();
                q.pop();
                if(f == 0){
                    if( (temp->val % 2) == 1 &&  temp->val > x ){ x = temp->val;}
                    else {return false;}
                }else{
                    if( (temp->val %2 ) == 0 &&  temp->val < x ) {x = temp->val;}
                    else {return false;}
                }
                if(temp->left){ q.push(temp->left);}
                if(temp->right){ q.push(temp->right);}
            }
            f = !f;
        }
        return true;
    }
};
