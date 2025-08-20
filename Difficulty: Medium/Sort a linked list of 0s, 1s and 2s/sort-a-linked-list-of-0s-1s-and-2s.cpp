/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    void func(Node *&temp,Node *&node,Node *&head){
        if(head==NULL){
            head=temp;
            node=temp;
        }
        else{
            node->next=temp;
            node=node->next;
        }
    }
    Node* segregate(Node* head) {
        Node *zeroHead=NULL;
        Node *oneHead=NULL;
        Node *twoHead=NULL;
        Node* a=zeroHead;
        Node* b=oneHead;
        Node* c=twoHead;
        Node* temp=head;
        while(temp!=NULL){
            if(temp->data==0){
                func(temp,a,zeroHead);
            }
            else if(temp->data==1){
                func(temp,b,oneHead);
            }
            else
            func(temp,c,twoHead);
            temp=temp->next;
        }
        if(a)
        a->next=NULL;
        if(b)
        b->next=NULL;
        if(c)
        c->next=NULL;
        if(a){
            if(b){
                a->next=oneHead;
                b->next=twoHead;
            }
            else
            a->next=twoHead;
            return zeroHead;
        }
        else if(b){
            b->next=twoHead;
            return oneHead;
        }
        else
        return twoHead;
    }
};