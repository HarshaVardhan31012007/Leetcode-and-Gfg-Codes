/* structure of list node:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        unordered_map<int,int>mpp;
        Node* temp=head2;
        while(temp!=NULL){
            mpp[temp->data]++;
            temp=temp->next;
        }
        temp=head1;
        Node* ans=new Node(-1);
        Node* it=ans;
        while(temp!=NULL){
            if(mpp[temp->data]>0){
                it->next=temp;
                it=it->next;
                mpp[temp->data]--;
            }
            temp=temp->next;
        }
        it->next=NULL;
        Node* finalans=ans->next;
        ans->next=NULL;
        delete ans;
        return finalans;
    } 
};