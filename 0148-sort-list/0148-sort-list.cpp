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
   ListNode *findmid(ListNode *head){
      ListNode *slow=head;
      ListNode *fast=head->next;
      while(fast&&fast->next){
          fast=fast->next->next;
           slow=slow->next;
      }
      return slow;

   }
   ListNode* merge(ListNode* left, ListNode* right) {
        if(left==0) return right;
        if(right==0) return left;
        ListNode *ans=new ListNode(-1);
        ListNode *mptr=ans;
        while(left!=NULL&&right!=NULL){
        if(left->val<=right->val){
            mptr->next=left;
            mptr=left;
            left=left->next;
        }
        else{
            mptr->next=right;
            mptr=right;
            right=right->next;
        }
    }
    if(left!=NULL){
        mptr->next=left;
    }
    if(right!=NULL){
        mptr->next=right;
    }
    ListNode *finalAns=ans->next;
    delete ans;
    return finalAns;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        //finding mid
        ListNode *mid=findmid(head);
        //divide list
        ListNode *left=head;
        ListNode *right=mid->next;
        mid->next=0;//NULL
        //RE
        left=sortList(left);
        right=sortList(right);
        //merge
        ListNode *MergeLL=merge(left,right);

        return MergeLL;
    }
};