/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // ListNode* solve(ListNode* head,int &n){
    //     if(!head||!head->next) return head;
    //     ListNode* nextNode=solve(head->next,n);
    //     n--;
    //     if(n==0){
    //         head->next=nextNode->next;
    //         nextNode->next=NULL;
    //         delete nextNode;
    //     }
    //     return head;
    // }
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     if(!head->next&&n==1)  return NULL;
    //     head=solve(head,n);
    //     if(n==1){
    //         ListNode* temp=head;
    //         head=head->next;
    //         temp->next=NULL;
    //         delete temp;
    //     }
    //     return head;
    // }



    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next&&n==1)  return NULL;
        ListNode* prev=head;
        ListNode* temp=head;
        for(int i=0;i<n;i++){
            temp=temp->next;
        }
        if(temp==NULL){
            ListNode* temp1=head;
            head=head->next;
            temp1->next=NULL;
            delete temp1;
            return head;
        }
        while(temp->next){
            prev=prev->next;
            temp=temp->next;
        }
        ListNode* node=prev->next;
        prev->next=prev->next->next;
        node->next=NULL;
        delete node;
        return head;
    }
};