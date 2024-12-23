class Solution {
public:
    // ListNode* solve(ListNode* &prev,ListNode* &curr){
    //     if(curr==NULL){
    //         return prev;
    //     }
    //     ListNode* forward=curr->next;
    //     curr->next=prev;
    //     prev=curr;
    //     curr=forward;
    //     return solve(prev,curr);
    // }
    ListNode* reverseList(ListNode* head) {
        // ListNode* prev=NULL;
        // ListNode* curr=head;
        // ListNode* reverseLinkedlist=solve(prev,curr);
        // return reverseLinkedlist;

        ListNode *prev=NULL;
        ListNode *curr=head;
        while(curr!=NULL){
            ListNode* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
};