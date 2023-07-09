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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL||head->next == NULL) return head;
    
        int sz=0;
        ListNode* t1 =head;
        while(t1){t1=t1->next;sz++;}
        
        ListNode* curr = new ListNode(0);
        curr->next = head;
        ListNode* pre = curr;
        ListNode* cur;
        ListNode* nex;
        
        while(sz >= k) {
            cur = pre->next;
            nex = cur->next;
            for(int i=1;i<k;i++) {
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            pre = cur;
            sz -= k;
        }
        return curr->next;
    }
};