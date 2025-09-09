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
    //bubble sort
    // void solve(ListNode* prev,ListNode* curr){
    //     if(!curr) return;
    //     solve(curr,curr->next);
    //     if(curr->next){
    //         if(curr->val>curr->next->val){
    //             swap(curr->val,curr->next->val);
    //         }
    //     }
    // }
    // ListNode* sortList(ListNode* head) {
    //         ListNode* prev=NULL;
    //         ListNode* curr=head;
    //         while(curr!=NULL){
    //             solve(prev,curr);
    //             curr=curr->next;
    //         }
    //         return head;
    // }


    ListNode* findmid(ListNode* head){
        // ListNode* slow=head;
        // ListNode* fast=head;
        // while(fast&&fast->next&&fast->next->next){
        //     slow=slow->next;
        //     fast=fast->next->next;
        // }
        // return slow;

         ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* a,ListNode* b){
        if(!a) return b;
        if(!b) return a;
        ListNode* ans=0;
        if(a->val<b->val){
            ans=a;
            ans->next=merge(a->next,b);
        }
        else{
            ans=b;
            ans->next=merge(a,b->next);
        }
        return ans;
    }
    ListNode* sortList(ListNode* head) {
           if(!head||!head->next) return head;

           ListNode* mid=findmid(head);
           ListNode* left=head;
           ListNode* right=mid->next;
           mid->next=0;
           
           left=sortList(left);
           right=sortList(right);

           head=merge(left,right);

           return head;
    }
};