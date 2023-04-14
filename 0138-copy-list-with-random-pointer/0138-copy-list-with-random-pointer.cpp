/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){return NULL;}
        Node* newHead = new Node(head->val);
        map<Node*,Node*> m;
        Node* tmp = head;
        Node* ntmp=newHead;
        m.insert({head,newHead});
        while(tmp){
            // cout<<ntmp->val<<endl;
            if(m.count(tmp->next)==0 && tmp->next){
                Node* newNext = new Node(tmp->next->val);
                ntmp -> next = newNext;
                m.insert({tmp->next,newNext});
            }else if(tmp->next){
                ntmp->next = m[tmp->next];
            }
            if(m.count(tmp->random)==0 && tmp->random){
                // cout<<tmp->random<<" "<<ntmp->val<<" ";
                Node* newRandom = new Node(tmp->random->val);
                ntmp -> random = newRandom;
                m.insert({tmp->random,newRandom});
                // cout<<newRandom<<" "<<ntmp->random<<endl;
            }else if(tmp->random){
                ntmp->random = m[tmp->random];
            }
            if(ntmp->val==11){
                // cout<<ntmp->random->val<<endl;
            }
            tmp=tmp->next;
            ntmp=ntmp->next;
        }
        // Node* n = newHead;
        // while(n){cout<<n<<endl;n=n->next;}
        return newHead;
    }
};