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
    ListNode* solve(ListNode*& slow,ListNode*& fast){
        if(!fast||!fast->next) return slow;
        fast=fast->next->next;
        slow=slow->next;
        return solve(slow,fast);
    }
    ListNode* middleNode(ListNode* head) {
        //M1 //1234 // 3 is ans // odd same ans
        //   ListNode* slow=head;
        //   ListNode* fast=head;
        //   while(fast!=NULL){
        //      fast=fast->next;
        //       if(fast!=NULL){
        //       fast=fast->next;
        //       slow=slow->next;
        //       }
        //   }
        //   return slow;

        
        //  ListNode* slow=head;
        //  ListNode* fast=head;
        //   while(fast&&fast->next){
        //     fast=fast->next->next;
        //     slow=slow->next;
        //   }
        //   return slow;
        ListNode* slow=head;
        ListNode* fast=head;
        return solve(slow,fast);
    }
};