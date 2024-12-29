/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
ListNode *hasCycle(ListNode *head){
     ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL){
           fast=fast->next;
           if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
            if(fast==slow){
                return slow;
            }
           }
        }
        return nullptr;
}
    ListNode *detectCycle(ListNode *head) {
        //  unordered_map<ListNode*,bool>mpp;
        //  ListNode *temp=head;
        // while(temp!=NULL){
        //     if(mpp[temp]==true){
        //         return temp;
        //     }
        //     mpp[temp]=true;
        //     temp=temp->next;
        // }
        // return nullptr; 

        ListNode *fast=hasCycle(head);
        if(!fast)
        return NULL;
        ListNode *slow=head;
        while(slow!=fast){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};