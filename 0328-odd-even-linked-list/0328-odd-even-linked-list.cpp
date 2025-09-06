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
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* oddHead=head;
        ListNode* evenHead=head->next;
        ListNode* temp=oddHead;
        ListNode* temp1=evenHead;
        while(temp1!=NULL&&temp1->next!=NULL){
            temp->next=temp->next->next;
            temp1->next=temp1->next->next;
            temp=temp->next;
            temp1=temp1->next;
        }
        temp->next=evenHead;
        if(temp1)
        temp1->next=NULL;
        return oddHead;
    }
};