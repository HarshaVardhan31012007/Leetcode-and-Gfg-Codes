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
    void solve(ListNode* head,int& k,int& k1,ListNode* &a,ListNode* &b){
        if(!head) return;
        k--;
        if(k==0)
        a=head;
        solve(head->next,k,k1,a,b);
        k1--;
        if(k1==0)
        b=head;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* a=NULL;
        ListNode* b=NULL;
        int k1=k;
        solve(head,k,k1,a,b);
        swap(a->val,b->val);
        return head;
    }
};