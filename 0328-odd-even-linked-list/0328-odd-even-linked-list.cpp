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
    ListNode* oddEvenList(ListNode* head) {
        // if(head==NULL||head->next==NULL||head->next->next==NULL){
        //     return head;
        // }
        // ListNode *prev=head;
        // ListNode *curr=head->next;
        // ListNode  *evenHead=head->next;
        // int len=0;
        // ListNode *temp=head;
        // while(temp!=NULL){
        //  len++;
        //  temp=temp->next;
        // }
        // if(len%2==1){
        // while(curr!=NULL){
        //     prev->next=curr->next;
        //     prev=curr;
        //     curr=curr->next; 
        // }
        // }
        // else{
        //     while(curr->next!=NULL){
        //     prev->next=curr->next;
        //     prev=curr;
        //     curr=curr->next; 
        // }
        // }
        // prev->next=evenHead;
        // return head;

        //method 2
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode *h1=head;
        ListNode *h2=head->next;
        ListNode *evenHead=h2;
        while(h2&&h2->next){
            h1->next=h2->next;
            h2->next=h2->next->next;
            h1=h1->next;
            h2=h2->next;
        }
        h1->next=evenHead;
        return head;
    }
};