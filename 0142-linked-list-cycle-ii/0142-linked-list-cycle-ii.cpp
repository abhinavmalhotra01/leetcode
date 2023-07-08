/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode *head) {
        if(!head){return 0;}
        if(!(head->next)){return 0;}
        ListNode *s1=head,*s2=head;
        while(s1 && s2 && s2->next){
            s1=s1->next;
            s2=s2->next->next;
            if(s1==s2){
                break;
            }
        }
        // if(s1 ==s2){cout<<s1->val;return s1;}
        // cout<<s1->val<<endl;
        if(s1!=s2){return NULL;}
        s1=head;
        while(s1!=s2){
            // cout<<s1->val <<" "<<s2->val<<endl;
            s1=s1->next;
            s2=s2->next;
        }
        // cout<<s1->val;
        return s1;
    }
};