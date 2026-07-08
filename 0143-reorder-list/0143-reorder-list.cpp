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
    ListNode* reverse(ListNode* curr){
        ListNode* prev=NULL;
        ListNode* temp=curr;
        while(temp){
            ListNode* forward=temp->next;
            temp->next=prev;
            prev=temp;
            temp=forward;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head->next||!head->next->next) return;
        ListNode* s=head;
        ListNode* f=head;
        while(f&&f->next){
            s=s->next;
            f=f->next->next;
        }
        ListNode* secondHead=reverse(s->next);
        s->next=NULL;
        ListNode* temp=head;
        ListNode* temp1=secondHead;
        while(temp1){
           ListNode* nextNode=temp->next;
           ListNode* nextNode1=temp1->next;
           temp1->next=temp->next;
           temp->next=temp1;
           temp=nextNode;
           temp1=nextNode1;
        }
    }
};