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
    // ListNode* reverseLL(ListNode* prev,ListNode* curr,int &len){
    //      while(curr!=NULL){
    //         len++;
    //         ListNode* forward=curr->next;
    //         curr->next=prev;
    //         prev=curr;
    //         curr=forward;
    //     }
    //     return prev;
    // }
    // ListNode* rotateRight(ListNode* head, int k) {
    //     if(!head) return head;
    //     ListNode* prev=NULL;
    //     ListNode* curr=head;
    //     int len=0;
    //     curr=reverseLL(prev,curr,len);
    //     prev=NULL;
    //     k=k%len;
    //     if(k==0){
    //        return reverseLL(prev,curr,len); 
    //     }
    //     head=curr;
    //     for(int i=0;i<k;i++){
    //         ListNode* forward=curr->next;
    //         curr->next=prev;
    //         prev=curr;
    //         curr=forward;
    //     }
    //     ListNode* a=NULL;
    //     ListNode* b=curr;
    //     len=0;
    //     head->next=reverseLL(a,b,len);
    //     return prev;
    // }



    //  ListNode* reverseLL(ListNode* prev,ListNode* curr,int &len){
    //      while(curr!=NULL){
    //         len++;
    //         ListNode* forward=curr->next;
    //         curr->next=prev;
    //         prev=curr;
    //         curr=forward;
    //     }
    //     return prev;
    // }
    // ListNode* rotateRight(ListNode* head, int k) {
    //     if(!head) return head;
    //     ListNode* prev=NULL;
    //     ListNode* curr=head;
    //     int len=0;
    //     curr=reverseLL(prev,curr,len);
    //     prev=NULL;
    //     k=k%len;
    //     head=curr;
    //     for(int i=0;i<k;i++){
    //         ListNode* forward=curr->next;
    //         curr->next=prev;
    //         prev=curr;
    //         curr=forward;
    //     }
    //     ListNode* a=NULL;
    //     ListNode* b=curr;
    //     len=0;
    //     if(k!=0)
    //     head->next=reverseLL(a,b,len);
    //     else
    //     return reverseLL(a,b,len);
    //     return prev;
    // }


    int getLength(ListNode* head){
        int len=0;
        while(head!=NULL){
            len++;
            head=head->next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;// len=0 then k%len is not valid //here rotate same we get null
        int len=getLength(head);
        k=k%len;
        if(k==0)
        return head;
        int moves=len-k-1;
        ListNode* newHead=NULL;
        ListNode* it=head;
        for(int i=0;i<moves;i++){
           it=it->next;
        }
        newHead=it->next;
        it->next=NULL;
        it=newHead;
        while(it->next){
            it=it->next;
        }
        it->next=head;
        return newHead;
    }
};