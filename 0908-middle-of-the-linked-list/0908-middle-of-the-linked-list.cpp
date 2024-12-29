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
    int getLength(ListNode *head){
        ListNode* temp=head;
        int len=0;
        while(temp!=NULL){
         len++;
         temp=temp->next;
        }
        return len;
    }
    ListNode* middleNode(ListNode* head) {
        //method 1
        int len=getLength(head);
         int jumps=len/2;
         ListNode *temp=head;
         while(jumps--){
            temp=temp->next;
         }
         return temp;
        // ListNode *slow=head;
        // ListNode *fast=head;
        // while(fast!=NULL){
        //     fast=fast->next;
        //     // if(fast==NULL)
        //     // break;
        //     // fast=fast->next;
        //     // slow=slow->next;
        //     if(fast!=NULL){
        //     fast=fast->next;
        //     slow=slow->next;
        //     }
        // }
        // return slow;
    }
};