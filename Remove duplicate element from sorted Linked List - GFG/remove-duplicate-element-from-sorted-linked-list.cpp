//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
    cout<<temp->data<<" ";
    temp=temp->next;
    }
}
Node* removeDuplicates(Node *root);
int main() {
	// your code goes here
	int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		Node *head = NULL;
        Node *temp = head;

		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
		Node *result  = removeDuplicates(head);
		print(result);
		cout<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
 Node* temp = head;
    while(temp!=NULL && temp->next !=NULL){
        while(temp!=NULL && temp->next!=NULL && temp->data == temp->next->data){
            
            Node* curr = temp->next;
            // 
            // if(temp->data==87){
            //     cout<<temp->next->data<<endl;
            //     cout<<curr->data<<endl;
            // }
            // delete temp->next;
            // cout<<
            temp->next = curr->next;
            // if(temp->data == 87){
            //     cout<<temp->next->data<<endl;
            //     cout<<curr->next->data<<endl;
            //     cout<<curr->data<<endl;
                
            // }
            // temp=temp->next;
        }
        temp=temp->next;
    }
    return head;

}