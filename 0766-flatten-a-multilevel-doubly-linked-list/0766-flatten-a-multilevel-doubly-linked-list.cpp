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
        //If you observe carefully,for reach sub problem we need tail of chid
         //so use while to traverse and find tail for each subproblem
         //it&&it->next consition in while is not correct because 1 null 2 null 3 null int his case 
         //it didn't even go to loop// use it for traversing and tail for tracking tail node
         //like prev and curr
        Node* it=head;
        Node* tail=NULL;
        while(it){
            if(it->child){
                Node* childTail=solve(it->child);
                childTail->next=it->next;
                if(it->next)// because 1 null 2 3 null case check
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