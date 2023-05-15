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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* fr1=head;
        for(int i=0;i<k-1;i++){
            if(!fr1){break;}
            fr1=fr1->next;
        }
        ListNode* fr2=head;
        int a=0;
        while(fr2!=NULL){
            a++;
            fr2=fr2->next;
        }
        fr2 = head;
        for(int i=0;i<a-k;i++){
            // cout<<fr2->val;
            if(!fr2){break;}
            fr2=fr2->next;
        }
        swap(fr2->val,fr1->val);
        return head;
    }
};