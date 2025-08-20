 class Node{
        public:
        int data;
        Node* next;
        Node(int value){
            this->data=value;
            this->next=NULL;
        }
};
class MyLinkedList {
public:
    Node *head=NULL;
    int get(int index) {
        Node* temp=head;
        for(int i=0;i<index;i++){
            temp=temp!=NULL?temp->next:NULL;
        }
        if(temp==NULL)
        return -1;
        return temp->data;
    }
    
    void addAtHead(int val) {
        if(head==NULL){
            head=new Node(val);
        }
        else{
            Node *newNode=new Node(val);
            newNode->next=head;
            head=newNode;
        }
    }
    
    void addAtTail(int val) {
        Node* temp=head;
        while(temp!=NULL&&temp->next!=NULL){
            temp=temp->next;
        }
        if(temp==NULL){
            head=new Node(val);
        }
        else{
            temp->next=new Node(val);
        }
    }
    
    void addAtIndex(int index, int val) {
        if(index==0){
            addAtHead(val);
            return;
        }
        Node* temp=head;
        for(int i=0;i<index-1;i++)
        temp=temp!=NULL?temp->next:NULL;
        if(temp!=NULL){
        Node* newNode=new Node(val);
        newNode->next=temp->next;
        temp->next=newNode;
        }
    }
    
    void deleteAtIndex(int index) {
        if(!head) return;
        if(index==0){
            if(head->next==NULL)
            head=NULL;
            else{
                Node *temp=head;
                head=head->next;
                delete temp;
            }
            return;
        }
        Node* temp=head;
        Node* prev=NULL;
        for(int i=0;i<index;i++){
             prev=temp;
             temp=temp!=NULL?temp->next:NULL;
        }
        if(temp!=NULL){
             prev->next=temp->next;
             Node* temp1=temp;
             temp1->next=NULL;
             delete temp1;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */