/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cn=0;
        ListNode* t = head;
        while(t){
            cn++;
            t=t->next;
        }
        ListNode* p = NULL;
        t = head;
        int c=cn-n;
        while(c--){
            p=t;
            t=t->next;
        }
        // cout<<p->val<<" "<<t->val<<endl;
        if(!p){
            return t->next;
        }
        p->next = t->next;
        // cout<<p->next->val<<endl;
        return head;
    }
};