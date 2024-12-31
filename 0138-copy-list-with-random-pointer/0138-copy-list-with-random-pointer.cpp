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
    // Node *solve(Node* head,unordered_map<Node*,Node*>&mpp){
    //     if(head==NULL)
    //     return NULL;
    //     Node*newHead=new Node(head->val);
    //     mpp[head]=newHead;
    //     newHead->next=solve(head->next,mpp);
    //     if(head->random){
    //         newHead->random=mpp[head->random];
    //     }//else case we no need to go map me by default zeros hota hai
    //     return newHead;
    // }
    Node* copyRandomList(Node* head) {
        //method 1
        // Node *temp=head;
        // Node *ansHead=NULL;
        // Node *ansTail=NULL;
        // unordered_map<Node*,Node*>mpp;
        // while(temp!=NULL){
        //    Node *newNode=new Node(temp->val);
        //    if(!ansTail&&!ansHead){
        //     ansHead=newNode;
        //     ansTail=newNode;
        //    } 
        //    else{
        //     ansTail->next=newNode;
        //     ansTail=newNode;
        //    }
        //    mpp[temp]=newNode;
        //    temp=temp->next;
        // }
        // temp=head;
        // while(temp!=NULL){
        //     if(temp->random)
        //     mpp[temp]->random=mpp[temp->random];
        //     else
        //     mpp[temp]->random=nullptr;
        //     temp=temp->next;
        // }
        // return ansHead;
        
        //method 2//recursive
        // unordered_map<Node*,Node*>mpp;
        // return solve(head,mpp);

        //method 3
        if(head==NULL)
        return NULL;
        //clone A->A'
        Node *temp=head;
        while(temp!=NULL){
            Node *cloneNode=new Node(temp->val);
            cloneNode->next=temp->next;
            temp->next=cloneNode;
            temp=temp->next->next;
        }
        //asign random links of A' with help of A
        temp=head;
        while(temp!=NULL){
            Node *clonedNode=temp->next;
            clonedNode->random=temp->random?temp->random->next:nullptr;
            temp=temp->next->next;
        }
        //detacH A from A'
        temp=head;
        Node *clonedHead=head->next;
        while(temp!=NULL){
            Node *clonedNode=temp->next;
            temp->next=temp->next->next;
            if(clonedNode->next){
                clonedNode->next=clonedNode->next->next;
            }
            temp=temp->next;
        }
        return clonedHead;
    }
};