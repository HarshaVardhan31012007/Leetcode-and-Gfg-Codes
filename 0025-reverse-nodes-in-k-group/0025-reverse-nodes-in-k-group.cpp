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
    // int getLength(ListNode* head){
    //    ListNode* temp=head;
    //    int len=0;
    //    while(temp!=NULL){
    //        len++;
    //        temp=temp->next;
    //    }
    //    return len;
    // }
    // ListNode* reverseKGroup(ListNode* head, int k) {
    //         int length=getLength(head);
    //         if(length<k) return head;
    //         ListNode* prev=NULL;
    //         ListNode* curr=head;
    //         for(int i=0;i<k;i++){
    //              ListNode* forward=curr->next;
    //              curr->next=prev;
    //              prev=curr;
    //              curr=forward;
    //         }
    //         head->next=curr;
    //         ListNode *t=head;
    //         head=prev;
    //         prev=t;
    //         length-=k;
    //         if(length<k) return head;
    //         while(length>=k){
    //              ListNode* temp=curr;
    //              ListNode* temp1=prev;
    //              for(int i=0;i<k;i++){
    //              ListNode* forward=curr->next;
    //              curr->next=prev;
    //              prev=curr;
    //              curr=forward;
    //             }
    //             temp->next=curr;
    //             temp1->next=prev;
    //             ListNode *t=temp;
    //             temp=prev;
    //             prev=t;
    //             length-=k;
    //         }
    //         return head;
    // }


      int getLength(ListNode* head){
       ListNode* temp=head;
       int len=0;
       while(temp!=NULL){
           len++;
           temp=temp->next;
       }
       return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
            int length=getLength(head);
            if(length<k) return head;
            ListNode* prev=NULL;
            ListNode* curr=head;
            for(int i=0;i<k;i++){
                 ListNode* forward=curr->next;
                 curr->next=prev;
                 prev=curr;
                 curr=forward;
            }
            if(curr){
                ListNode* recHead=reverseKGroup(curr,k);
                head->next=recHead;
            }
           return prev;
    }
};