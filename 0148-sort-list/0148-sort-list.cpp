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
    ListNode* sortList(ListNode* head) {
        if(!head){return head;}
        if(!head->next){return head;}
        ListNode* slow=head,*fast=head->next->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* ne = slow->next;
        slow->next = NULL;
        ListNode* l = sortList(head);
        ne = sortList(ne);
        return head= merge(ne,l);
    }
    ListNode* merge(ListNode* l , ListNode* r){
        if(!l){return r;}
        if(!r){return l;}
        ListNode* curr=new ListNode();
        ListNode* out=curr;
        while(l&&r){
            if(l->val<=r->val){
                out->next = l;
                l=l->next;
            }
            else{
                out->next = r;
                r=r->next;
            }
            out=out->next;
        }
        if(l){
            out->next =l;
        }
        if(r){
            out->next =r;
        }
        return curr->next;
    }
};