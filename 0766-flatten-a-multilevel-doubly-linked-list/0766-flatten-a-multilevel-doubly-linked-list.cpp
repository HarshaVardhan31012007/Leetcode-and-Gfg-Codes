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
    Node* solve(Node *head){
        //no need
        //  if(!head)
        // return NULL;
        auto it=head;
        auto tail=it;//for tracking tail node//due to this empty case also runs
        while(it){
            if(it->child){
                Node *childTail=solve(it->child);
                Node *temp=it->next;
                it->next=it->child;
                it->child=NULL;
                it->next->prev=it;
                childTail->next=temp;
                if(temp!=NULL){
                    temp->prev=childTail;
                }
            }
            tail=it;
            it=it->next;
        }
        return tail;
    }
    Node* flatten(Node* head) {
        //no need
        // if(!head)
        // return NULL;

       solve(head);

       return head;
    }
};