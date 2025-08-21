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
    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //     ListNode* ans=new ListNode(-1);
    //     ListNode* it=ans;
    //     int carry=0;
    //     while(l1||l2||carry){
    //         int a=l1!=NULL?l1->val:0;
    //         int b=l2!=NULL?l2->val:0;
    //         int sum=a+b+carry;
    //         it->next=new ListNode(sum%10);
    //         it=it->next;
    //          carry=sum/10;
    //         l1=l1!=NULL?l1->next:l1;
    //         l2=l2!=NULL?l2->next:l2;
    //     }
    //     ListNode* fans=ans->next;
    //     delete ans;
    //     return fans;
    // }

     ListNode* solve(ListNode* l1,ListNode* l2,int carry){
        if(!l1&&!l2&&!carry) return NULL;
            int a=l1!=NULL?l1->val:0;
            int b=l2!=NULL?l2->val:0;
            int sum=a+b+carry;
            ListNode* ans=new ListNode(sum%10);
            ans->next=solve(l1!=NULL?l1->next:l1,l2!=NULL?l2->next:l2,sum/10);
            return ans;
     }
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       return solve(l1,l2,0);
    }
};