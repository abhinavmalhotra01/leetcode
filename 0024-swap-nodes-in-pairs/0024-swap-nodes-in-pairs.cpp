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
    ListNode* swapPairs(ListNode* head) {
        ListNode* a = head;
        if(a==NULL){return a;}
        ListNode* b = head->next;
        while(a!=NULL && b!=NULL){
            swap(a->val,b->val);
            if(a->next->next == NULL){break;}
            a=a->next->next;
            b=b->next->next;
        }
        return head;
    }
};