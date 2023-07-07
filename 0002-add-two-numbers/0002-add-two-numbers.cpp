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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t=new ListNode(0);
        ListNode* h=t;
        while(l1 && l2){
            if(l1->val + l2->val < 10){
                t->val = l1->val + l2->val;
                // cout<<t->val<<" ";
            }else{
                if(l1->next){
                l1->next->val+=1;}
                else if(l2->next){
                    l2->next->val+=1;
                }else{
                    t->val = (l1->val + l2->val)%10;
                    t->next = new ListNode((l1->val+l2->val)/10);
                    // cout<<"a"<<t->val<<endl;
                    return h;
                    // l1=l1->next;l2=l2->next;
                    // continue;
                }
                t->val = (l1->val + l2->val)%10;
                // cout<<t->val<<" ";
            }
            l1=l1->next;l2=l2->next;
            if(l1 || l2){
                t->next = new ListNode(0);
                t=t->next;
            }
        }
        // cout<<endl;
        while(l1){
            if(l1->val >=10){
                // cout<<"a";
                t->val = (l1->val)%10;
                // cout<<t->val<<" "<<l1->val<<endl;
                if(l1->next){
                    t->next = new ListNode(0);
                    t=t->next;
                    l1->next->val +=1;
                }else{
                    t->next = new ListNode((l1->val)/10);
                }
                l1=l1->next;
                continue;
            }
            t->val = l1->val;
            // cout<<t->val<<" ";
            l1=l1->next;
            if(l1 ){
                t->next = new ListNode(0);
                t=t->next;
            }
        }while(l2){
            if(l2->val >=10){
                // cout<<"a";
                t->val = (l2->val)%10;
                // cout<<t->val<<" "<<l2->val<<endl;
                if(l2->next){
                    t->next = new ListNode(0);
                    t=t->next;
                    l2->next->val +=1;
                }else{
                    t->next = new ListNode((l2->val)/10);
                }
                l2=l2->next;
                continue;
            }
            t->val=l2->val;
            // cout<<t->val<<" ";
            l2=l2->next;
            if(l2){
                t->next = new ListNode(0);
                t=t->next;
            }
        }
        return h;
    }
};