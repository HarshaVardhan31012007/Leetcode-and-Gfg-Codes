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
        //method 1
        Node *temp=head;
        Node *ansHead=NULL;
        Node *ansTail=NULL;
        unordered_map<Node*,Node*>mpp;
        while(temp!=NULL){
           Node *newNode=new Node(temp->val);
           if(!ansTail&&!ansHead){
            ansHead=newNode;
            ansTail=newNode;
           } 
           else{
            ansTail->next=newNode;
            ansTail=newNode;
           }
           mpp[temp]=newNode;
           temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            if(temp->random)
            mpp[temp]->random=mpp[temp->random];
            else
            mpp[temp]->random=nullptr;
            temp=temp->next;
        }
        return ansHead;
    }
};