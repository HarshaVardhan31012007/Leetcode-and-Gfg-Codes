/*
// structure of the node is as follows

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
    struct Node* makeUnion(struct Node* head1, struct Node* head2) {
        // map<int,Node*>mpp;
        // Node* temp=head1;
        // while(temp!=NULL){
        //     if(mpp.count(temp->data)==0)
        //     mpp[temp->data]=temp;
        //     temp=temp->next;
        // }
        // temp=head2;
        // while(temp!=NULL){
        //     if(mpp.count(temp->data)==0)
        //     mpp[temp->data]=temp;
        //     temp=temp->next;
        // }
        // Node* ans=NULL;
        // Node* it1=ans;
        // for(auto it=mpp.begin();it!=mpp.end();it++){
        //     if(!ans){
        //       ans=it->second;
        //       it1=ans;
        //     }
        //     else{
        //         it1->next=it->second;
        //         it1=it1->next;
        //     }
        // }
        // return ans;
        
        
        
        
        map<int,int>mpp;
        Node* temp=head1;
        while(temp!=NULL){
            mpp[temp->data]++;
            temp=temp->next;
        }
        temp=head2;
        while(temp!=NULL){
            mpp[temp->data]++;
            temp=temp->next;
        }
        Node* ans=NULL;
        Node* it1=ans;
        for(auto it=mpp.begin();it!=mpp.end();it++){
            if(!ans){
               ans=new Node(it->first);
               it1=ans;
            }
            else{
                it1->next=new Node(it->first);
                it1=it1->next;
            }
        }
        return ans;
    }
};