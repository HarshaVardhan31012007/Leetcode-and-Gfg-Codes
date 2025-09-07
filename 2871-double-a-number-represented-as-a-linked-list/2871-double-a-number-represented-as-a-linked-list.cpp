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
    void solve(ListNode* curr,int& carry){
        if(!curr) return;
        solve(curr->next,carry);
        int val=curr->val*2+carry;
        curr->val=val%10;
        carry=val/10;
    }
    ListNode* doubleIt(ListNode* head) {
        int carry=0;
        solve(head,carry);
        if(carry){
        ListNode* newHead=new ListNode(carry);
        newHead->next=head;
        return newHead;
        }
        return head;
    }
};