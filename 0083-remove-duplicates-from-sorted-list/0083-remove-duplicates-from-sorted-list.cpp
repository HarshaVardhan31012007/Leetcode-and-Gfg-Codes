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
    ListNode* deleteDuplicates(ListNode* head) {
        // if(head==NULL||head->next==NULL) return head;
        // ListNode* prev=head;
        // ListNode* curr=head->next;
        // while(curr!=NULL){
        //     if(prev->val!=curr->val){
        //          prev=prev->next;
        //          curr=curr->next;
        //     }
        //     else{
        //     prev->next=curr->next;
        //     ListNode* temp=curr;
        //     curr=curr->next;
        //     temp->next=NULL;
        //     delete temp;
        //     }
        // }
        // return head;

        if(head==NULL||head->next==NULL) return head;
        ListNode* prev=head;
        ListNode* curr=head->next;
        while(curr!=NULL){
            if(prev->val!=curr->val){
                 prev=prev->next;
            }
            else{
            prev->next=curr->next;
            curr->next=NULL;
            delete curr;
            }
            curr=prev->next;
        }
        return head;


        //  if(head==NULL||head->next==NULL) return head;
        // ListNode* prev=head;
        // ListNode* curr=head->next;
        // while(curr!=NULL){
        //     if(prev->val!=curr->val){
        //        prev->next=curr;
        //        prev=curr;
        //        curr=curr->next;
        //     }
        //     else{
        //     curr=curr->next;
        //     }
        // }
        // prev->next=NULL;
        // return head;
    }
};