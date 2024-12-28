class Solution {
public:
    // ListNode* solve(ListNode* &prev,ListNode* &curr){
    //     if(curr==NULL){
    //     // one way if use void
    //     //   head=prev;
    //     //    second way if use ListNode*
    //         return prev;
    //     }
    //     ListNode* forward=curr->next;
    //     curr->next=prev;
    //     prev=curr;
    //     curr=forward;
    //     return solve(prev,curr);
    // //or return solve(curr,forward);
    // }
    ListNode* reverseList(ListNode* head) {
        // ListNode* prev=NULL;
        // ListNode* curr=head;
        // ListNode* reverseLinkedlist=solve(prev,curr);
        // return reverseLinkedlist;
        // ListNode *prev=NULL;
        // ListNode *curr=head;
        // while(curr!=NULL){
        //     ListNode* forward=curr->next;
        //     curr->next=prev;
        //     prev=curr;
        //     curr=forward;
        // }
        // return prev;
        //method 3
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode *chotahead=reverseList(head->next);

        head->next->next=head;
        head->next=NULL;

        return chotahead;
    }
};