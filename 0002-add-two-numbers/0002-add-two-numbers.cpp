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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode *temp1=l1;
        ListNode *temp2=l2;
        while(temp1!=NULL&&temp2!=NULL){
            int sum=temp1->val+temp2->val+carry;
            temp1->val=sum%10;
            temp2->val=sum%10;
            carry=sum/10;
            if(temp1->next==NULL&&temp2->next==NULL&&carry!=0){
            ListNode *newNode=new ListNode(carry);
            temp1->next=newNode;
            temp1=newNode;
           }
           temp1=temp1->next;
           temp2=temp2->next;
        }
        int ans=0;
         while(temp1==NULL&&temp2!=NULL){
            int sum=temp2->val+carry;
            temp2->val=sum%10;
            carry=sum/10;
            if(temp2->next==NULL&&carry!=0){
            ListNode *newNode=new ListNode(carry);
            temp2->next=newNode;
            temp2=newNode;
           }
           temp2=temp2->next;
           ans=1;
        }
        while(temp1!=NULL&&temp2==NULL){
            int sum=temp1->val+carry;
            temp1->val=sum%10;
            carry=sum/10;
             if(temp1->next==NULL&&carry!=0){
            ListNode *newNode=new ListNode(carry);
            temp1->next=newNode;
            temp1=newNode;
           }
           temp1=temp1->next;
           ans=0;
        }
        return (ans==0)?l1:l2;
        // bool ans=0;
        // if(l2==NULL&&l1!=NULL){
        //  while(l1!=NULL){
        //     int sum=l1->val+carry;
        //     l1->val=sum%10;
        //     carry=sum/10;
        //     l1=l1->next;
        // }
        // ans=1;
        // }
        // else if(l1==NULL&&l2!=NULL){
        //    while(l2!=NULL){
        //     int sum=l2->val+carry;
        //     l2->val=sum%10;
        //     carry=sum/10;
        //     l2=l2->next;
        // }
        // ans=0;
        // }
        // if(carry&&ans==1){
        //  ListNode *newNode=new ListNode(carry);
        //  newNode->next=l1;
        // }
        //  if(carry&&ans==0){
        //  LnewNode=new ListNode(carry);
        //  newNode->next=l2;
        // }
        // if(ans==0){
        //     ListNode *prev=NULL;
        //     reverselist(prev,l2);
        // }
        // else{
        //     ListNode *prev=NULL;
        //     reverselist(prev,l1);
        // }
        // return newNode;
    }
};