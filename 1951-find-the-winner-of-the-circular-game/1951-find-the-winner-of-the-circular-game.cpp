class Solution {
public:
    // class Node{
    //     public:
    //     int data;
    //     Node* next;
    //     Node(int val){
    //         this->data=val;
    //         this->next=NULL;
    //     }
    // };

    //1-indexed based
    // int solve(int n,int k){
    //     if(n==1) return 1;
    //     return (solve(n-1,k)+k-1)%n+1;
    // }

    //0-indexed based
    // int solve(int n,int k){
    //     if(n==1) return 0;
    //     return (solve(n-1,k)+k)%n;
    // }
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




        // Node* head=new Node(1);
        // Node* it=head;
        // for(int i=2;i<=n;i++){
        //     it->next=new Node(i);
        //     it=it->next;
        // }
        // it->next=head;
        // Node* prev=it;// if k is 1 then we need this
        // it=head;
        // while(it->next!=it){
        //     for(int i=0;i<k-1;i++){
        //         prev=it;
        //         it=it->next;
        //     }
        //     prev->next=it->next;
        //     it->next=NULL;
        //     delete it;
        //     it=prev->next;
        // }
        // return it->data;


        //Recursion
        //1-indexed
        //return solve(n,k);
        //0-indexed
       // return solve(n,k)+1;//+1 is to convert 0 to 1 indexed


       //iterative
       //optimizing recursive logic
       int ans=0;//i=1 answer we follow 0-indexed order later we convert to 1-indexed
       for(int i=2;i<=n;i++){
            ans=(ans+k)%i;//calculating curr ans using prev ans
       }
       return ans+1;
    }
};