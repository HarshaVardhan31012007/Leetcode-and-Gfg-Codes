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
    // ListNode* mergeNodes(ListNode* head) {
    //     ListNode* temp=head;
    //     ListNode* ans=new ListNode(-1);
    //     ListNode* it=ans;
    //     int sum=0;
    //     while(temp!=NULL){
    //         if(temp->val==0){
    //             if(sum!=0){
    //             it->next=new ListNode(sum);
    //             it=it->next;
    //             sum=0;
    //             }
    //         }
    //         else
    //         sum+=temp->val;
    //         temp=temp->next;
    //     }
    //     it->next=NULL;
    //     ListNode* finalans=ans->next;
    //     ans->next=NULL;
    //     delete ans;
    //     return finalans;
    // }


    // ListNode* mergeNodes(ListNode* head) {
    //     ListNode* ans=head;
    //     ListNode* prev=head;
    //     ListNode* temp=head->next;
    //     int sum=0;
    //     while(temp!=NULL){
    //         if(temp->val==0){
    //             temp->val=sum;
    //             prev=prev->next;
    //             sum=0;
    //         }
    //         else{
    //         sum+=temp->val;
    //         prev->next=temp->next;
    //         temp->next=NULL;
    //         delete temp;
    //         }
    //         temp=prev->next;
    //     }
    //     ListNode* finalans=ans->next;
    //     //this is correct but online judge of leetcode after submitting it may use it
    //     // ans->next=NULL;
    //     // delete ans;
    //     return finalans;
    // }

    ListNode* mergeNodes(ListNode* head) {
       ListNode* prev=NULL;
       ListNode* slow=head;
       ListNode* fast=head->next;
       int sum=0;
       while(fast!=NULL){
           if(fast->val!=0){
            sum=sum+fast->val;
           }
           else{
            slow->val=sum;
            prev=slow;
            slow=slow->next;
            sum=0;
           }
           fast=fast->next;
       }
       prev->next=NULL;
       while(slow){
        ListNode* temp=slow->next;
        slow->next=NULL;
        delete slow;
        slow=temp;
       }
       return head;
    }
};