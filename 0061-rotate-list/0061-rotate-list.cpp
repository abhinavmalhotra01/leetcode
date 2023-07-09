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
    // ListNode* reverseList(ListNode* t){
    //     ListNode* pre=NULL;
    //     ListNode* cur=t;
    //     ListNode* nex;
    //     while(cur){
    //         nex= cur->next;
    //         cur->next = pre;
    //         pre=cur;
    //         cur=nex;
    //     }
    //     return pre;
    // }
    // ListNode* reverseK(ListNode* head , ListNode* t){
    //     ListNode* pre=NULL;
    //     ListNode* cur=t;
    //     ListNode* nex;
    //     while(cur->next != t){
    //         nex= cur->next;
    //         cur->next = pre;
    //         pre=cur;
    //         cur=nex;
    //     }
    //     return pre;
    // }
public:
    ListNode* rotateRight(ListNode* head, int k) {
//         ListNode* t = reverseList(head);
//         ListNode* t2=head;
//         k--;
//         while(k--){
//             t2=t2->next;
//         }
//         ListNode*t3 = reverseK(head,t2);
//         head=t3;
        if(head == NULL||head->next == NULL||k == 0) return head;
        ListNode* temp = head;
        int sz = 1;
        while(temp->next != NULL) {
            ++sz;
            temp = temp->next;
        }
        temp->next = head;
        k = k%sz; 
        int end = sz-k; 
        while(end--) temp = temp->next;
        head = temp->next;
        temp->next = NULL;
            
        return head;   
    }
};