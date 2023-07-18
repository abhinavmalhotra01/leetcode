/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL){
            return "";
        }
        string out = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr==NULL){
                out.append("null");
                out.push_back(',');
            }
            else{
                out.append(to_string(curr->val)+',');
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return out;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0){
            return NULL;
        }
        // TreeNode* root = new TreeNode(data[0]);
        // queue<char> q;
        // q.push(data[0]);
        // while(!q.empty()){
        //     char curr = q.front();
        //     int current = curr-'0';

        // }
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            getline(s,str,',');
            if(str[0]=='n' && str[1]=='u' && str[2]=='l' && str[3]=='l'){
                // cout<<endl;
                curr->left = NULL;
            }else{
                TreeNode* L = new TreeNode(stoi(str));
                curr->left = L;
                q.push(L);
            }
            getline(s,str,',');
            if(str[0]=='n' && str[1]=='u' && str[2]=='l' && str[3]=='l'){
                // cout<<0<<endl;
                curr->right = NULL;
            }else{
                TreeNode* R = new TreeNode(stoi(str));
                curr->right = R;
                q.push(R);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;