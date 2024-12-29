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
        //method 1
        // int carry=0;
        // ListNode *temp1=l1;
        // ListNode *temp2=l2;
        // while(temp1!=NULL&&temp2!=NULL){
        //     int sum=temp1->val+temp2->val+carry;
        //     temp1->val=sum%10;
        //     temp2->val=sum%10;
        //     carry=sum/10;
        //     if(temp1->next==NULL&&temp2->next==NULL&&carry!=0){
        //     ListNode *newNode=new ListNode(carry);
        //     temp1->next=newNode;
        //     temp1=newNode;
        //    }
        //    temp1=temp1->next;
        //    temp2=temp2->next;
        // }
        // int ans=0;
        //  while(temp1==NULL&&temp2!=NULL){
        //     int sum=temp2->val+carry;
        //     temp2->val=sum%10;
        //     carry=sum/10;
        //     if(temp2->next==NULL&&carry!=0){
        //     ListNode *newNode=new ListNode(carry);
        //     temp2->next=newNode;
        //     temp2=newNode;
        //    }
        //    temp2=temp2->next;
        //    ans=1;
        // }
        // while(temp1!=NULL&&temp2==NULL){
        //     int sum=temp1->val+carry;
        //     temp1->val=sum%10;
        //     carry=sum/10;
        //      if(temp1->next==NULL&&carry!=0){
        //     ListNode *newNode=new ListNode(carry);
        //     temp1->next=newNode;
        //     temp1=newNode;
        //    }
        //    temp1=temp1->next;
        //    ans=0;
        // }
        // return (ans==0)?l1:l2;
       

       //method 2
        int carry=0;
        ListNode *ans=new ListNode(-1);
        ListNode *it=ans;
        ListNode *temp1=l1;
        ListNode *temp2=l2;
        while(temp1||temp2||carry){
            int a=temp1?temp1->val:0;
            int b=temp2?temp2->val:0;
            int sum=a+b+carry;
            int digit=sum%10;
            carry=sum/10;
            it->next=new ListNode(digit);
            it=it->next;
           temp1=temp1?temp1->next:nullptr;
           temp2=temp2?temp2->next:nullptr;
        }
        ListNode *finalAns=ans->next;
        return finalAns;
    }
};