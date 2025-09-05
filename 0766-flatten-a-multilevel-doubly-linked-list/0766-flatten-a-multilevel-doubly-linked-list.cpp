/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    // Node* flatten(Node* head) {
    //     if(head==NULL) return NULL;
    //     if(head->child){
    //       Node* temp=head->next;
    //       head->child->prev=head;
    //       head->next=flatten(head->child);
    //       head->child=NULL;
    //       Node* p=head;
    //       while(p->next!=NULL)
    //       p=p->next;
    //       p->next=temp;
    //       if(temp)
    //       temp->prev=p;
    //     }
    //     else
    //     head->next=flatten(head->next);
    //     return head;
    // }



    Node* solve(Node* head){
        Node* it=head;
        Node* tail=NULL;
        while(it){
            if(it->child){
                Node* childTail=solve(it->child);
                childTail->next=it->next;
                if(it->next)
                it->next->prev=childTail;
                it->next=it->child;
                it->child->prev=it;
                it->child=NULL;
                tail=childTail;
                it=childTail->next;
            }
            else{
            tail=it;
            it=it->next;
            }
        }
        return tail;
    }
    Node* flatten(Node* head) {
      solve(head);
      return head;
    }
};