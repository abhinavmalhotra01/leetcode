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
    ListNode* add(ListNode* l1,ListNode*l2,int& c){
        if(!l1){
            return NULL;
        }
        ListNode*temp=new ListNode(0);
        temp->next=add(l1->next,l2->next,c);
        int res=l1->val+l2->val+c;
        temp->val=res%10;
        c=res/10;
        return temp; 
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       int c1=0,c2=0;
        ListNode*t1=l1,*t2=l2;
        while(t1){c1++;t1=t1->next;}
        while(t2){c2++;t2=t2->next;}
        int d = abs(c1-c2);
        // cout<<c1<<" "<<c2<<endl;
        ListNode* t = new ListNode(-1);
        ListNode* h =t;
        while(d--){
            t->next = new ListNode(0);
            t=t->next;
        }
        if(c1>c2){
            t->next = l2;
            l2=h->next;
        }else{
            t->next = l1;
            l1=h->next;
        }
        int c=0;
        ListNode* out = add(l1,l2,c);
        if(c){
            ListNode*ans=new ListNode(1);
            ans->next=out;
            return ans;
        }
        return out;
    }
};