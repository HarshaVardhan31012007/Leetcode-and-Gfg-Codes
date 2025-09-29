class Solution {
public:
    class Node{
        public:
        int data;
        Node* next;
        Node(int val){
            this->data=val;
            this->next=NULL;
        }
    };
    int findTheWinner(int n, int k) {
        // queue<int>q;
        // for(int i=1;i<=n;i++){
        //     q.push(i);
        // }
        // while(q.size()>1){
        //     int count=k-1;
        //     while(count--){
        //         q.push(q.front());
        //         q.pop();
        //     }
        //     q.pop();
        // }
        // return q.front();


        Node* head=new Node(1);
        Node* it=head;
        for(int i=2;i<=n;i++){
            it->next=new Node(i);
            it=it->next;
        }
        it->next=head;
        Node* prev=it;// if k is 1 then we need this
        it=head;
        while(it->next!=it){
            for(int i=0;i<k-1;i++){
                prev=it;
                it=it->next;
            }
            prev->next=it->next;
            it->next=NULL;
            delete it;
            it=prev->next;
        }
        return it->data;
    }
};