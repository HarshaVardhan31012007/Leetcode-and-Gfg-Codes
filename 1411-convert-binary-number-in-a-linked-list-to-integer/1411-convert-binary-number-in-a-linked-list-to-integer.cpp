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
    int solve(ListNode *head,int &c){
        if(!head) return 0;
        int ans=solve(head->next,c);
        if(head->val)
        ans+=head->val*c;
        c=c*2;
        return ans;
    }
    int getDecimalValue(ListNode* head) {
        int c=1;
        return solve(head,c);
    }
};