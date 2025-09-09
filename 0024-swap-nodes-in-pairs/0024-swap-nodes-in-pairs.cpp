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
    // ListNode* swapPairs(ListNode* head) {
    //     if(!head||!head->next) return head;
    //     ListNode* temp=head->next->next;
    //     head->next->next=head;
    //     ListNode* newHead=head->next;
    //     head->next=swapPairs(temp);
    //     return newHead;
    // }



     ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* first=head;
        ListNode* sec=head->next;
        ListNode* prev=NULL;
        while(first&&sec){
             ListNode* third=sec->next;
             sec->next=first;
             first->next=third;
             if(prev){
                prev->next=sec;
             }else{
                head=sec;
             }
             prev=first;
             first=third;
             if(third){
                sec=third->next;
             }
             else
             sec=NULL;
        }
        return head;
    }
};