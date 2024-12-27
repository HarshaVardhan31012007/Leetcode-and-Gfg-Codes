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
    int getLength(ListNode *head){
        ListNode *temp=head;
        int len=0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        //base cases
        //empty case
        if(head==NULL){
            return head;
        }
        //single node case
        if(head->next==NULL){
            return head;
        }
        //length less than k
        int len=getLength(head);
        if(len<k){
            return head;
        }
        // 1 case
        ListNode *prev=NULL;
        ListNode *curr=head;
        int position=0;
        while(position<k){
            ListNode *forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            position++;
        }
        //recursive calls
        if(curr!=NULL){
            ListNode *recursivehead=reverseKGroup(curr,k);
            head->next=recursivehead;
        }
        return prev;
    }
};