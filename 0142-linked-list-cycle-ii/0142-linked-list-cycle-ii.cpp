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
    ListNode *detect(ListNode* &head,ListNode* &prev){
        ListNode* s=head;
        ListNode* f=head;
        while(f!=NULL){
            f=f->next;
            if(f!=NULL){
                prev=s;
                f=f->next;
                s=s->next;
                if(s==f)
                return s;
            }
        }
        return nullptr;
    }
    ListNode* getsp(ListNode* slow,ListNode* fast,ListNode* &prev){
         while(slow!=fast){
             prev=slow;
             slow=slow->next;
             fast=fast->next;
         }
         return slow;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode *prev=NULL;
        ListNode *hasCycle=detect(head,prev);
        if(!hasCycle)
        return nullptr;
        ListNode* sp=getsp(hasCycle,head,prev);
        return sp;
    }
};