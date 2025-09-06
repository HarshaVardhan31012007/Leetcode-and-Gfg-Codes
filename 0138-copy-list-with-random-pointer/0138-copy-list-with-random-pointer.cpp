/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       if(!head) return head;
       unordered_map<Node*,Node*>mpp;
       mpp[nullptr]=nullptr;
       Node* newHead=new Node(head->val);
       Node* ans=newHead;
       mpp[head]=ans;
       Node* temp=head;
       temp=temp->next;
       while(temp!=NULL){
         ans->next=new Node(temp->val);
         ans=ans->next;
         mpp[temp]=ans;
         temp=temp->next;
       }
       ans->next=NULL;
       temp=head;
       while(temp!=NULL){
        Node* a=temp->random;
        mpp[temp]->random=mpp[a];
        temp=temp->next;
       }
       return newHead;
    }
};