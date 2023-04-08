/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL){return NULL;}
        Node* out = new Node(node->val);
        queue<Node*> q;
        q.push(node);
        unordered_map<Node*,Node*> m;
        m[node]=out;
        while(!q.empty()){
            Node* curr= q.front();
            Node* cur2 = m[curr];
            q.pop();
            for(auto e : curr->neighbors){
                if(m.count(e)==0){
                    Node* new_node = new Node(e->val);
                    m[e]=new_node;
                    cur2->neighbors.push_back(new_node);
                    q.push(e);
                }else{
                    cur2->neighbors.push_back(m[e]);
                }
            }
        }
        return out;
    }
};