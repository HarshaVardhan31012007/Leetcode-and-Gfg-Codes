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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return NULL;
        ListNode* s=head;
        ListNode* f=head;
        ListNode* prev=NULL;
        while(f&&f->next){
           prev=s;
           s=s->next;
           f=f->next->next;
        }
        prev->next=s->next;
        s->next=NULL;
        delete s;
        return head;
    }
};