/*
delete n nodes after m nodes
  The input list will have at least one element
  Node is defined as

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    Node* linkdelete(Node* head, int q, int p) {
        Node* it=head;
        Node* prev=head;
        while(it){
        int m=p;
        int n=q;
        while(it&&m--){
            prev=it;
            it=it->next;
        }
        
        while(it&&n--){
            Node* temp=it;
            it=it->next;
            temp->next=NULL;
            delete temp;
        }
        if(prev)
        prev->next=it;
        }
        return head;
    }
};