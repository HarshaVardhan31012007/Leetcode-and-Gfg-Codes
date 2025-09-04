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
    Node* flatten(Node* head) {
        if(head==NULL) return NULL;
        if(head->child){
          Node* temp=head->next;
          head->child->prev=head;
          head->next=flatten(head->child);
          head->child=NULL;
          Node* p=head;
          while(p->next!=NULL)
          p=p->next;
          p->next=temp;
          if(temp)
          temp->prev=p;
        }
        else
        head->next=flatten(head->next);
        return head;
    }
};