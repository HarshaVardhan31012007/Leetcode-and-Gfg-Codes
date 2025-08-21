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
    ListNode *detectCycle(ListNode *head) {
        ListNode *prev=NULL;
        ListNode *hasCycle=detect(head,prev);
        if(!hasCycle)
        return nullptr;
        ListNode* slow=hasCycle;
        ListNode* fast=head;
        while(slow!=fast){
             prev=slow;
             slow=slow->next;
             fast=fast->next;
         }
         prev->next=NULL;
         //or
        //  ListNode* temp=hasCycle;// it will not work if slow==fast eqaul point and 
        // loop starting point is same // or complete loop(no node is outside loop)
        //  while(temp->next!=slow){
        //     temp=temp->next;
        //  }
        //  temp->next=NULL
         return slow;
    }
};