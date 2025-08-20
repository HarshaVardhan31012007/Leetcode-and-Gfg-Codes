/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverseLL(Node* head){
        Node* prev=NULL;
        Node* temp=head;
        while(temp!=NULL){
            Node* forward=temp->next;
            temp->next=prev;
            prev=temp;
            temp=forward;
        }
        return prev;
    }
    Node* addOne(Node* head) {
       head=reverseLL(head);
       Node *curr=head;
       int carry=1;
       while(curr!=NULL){
           int sum=curr->data+carry;
           curr->data=sum%10;
           carry=sum/10;
           if(!curr->next&&carry){
             curr->next=new Node(carry);
             carry=0;
           }
           if(carry==0)
           break;
           curr=curr->next;
       }
       head=reverseLL(head);
       return head;
    }
};                                                        