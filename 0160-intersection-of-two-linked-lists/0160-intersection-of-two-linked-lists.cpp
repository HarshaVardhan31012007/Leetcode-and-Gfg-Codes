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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // this is wrong because when it is becoming null at in that iteration you should move to head
        // ListNode* a=headA;
        // ListNode* b=headB;
        // while(a!=b){
        //     if(!a) a=headB;
        //     if(!b) b=headA;
        //     a=a->next;
        //     b=b->next;
        // }
        // return a;

        
        // ListNode* a=headA;
        // ListNode* b=headB;
        // while(a!=b){
        //     if(!a) a=headB;
        //     if(!b) b=headA;
        //     if(a==b) return a;// here iteration completely perfectly that means if null in previous iteration it correct now
        //     a=a->next;
        //     b=b->next;
        // }
        // return a;

        ListNode* a=headA;
        ListNode* b=headB;
        while(a!=b){
            a=a->next;
            b=b->next;
            if(a==NULL&&b==NULL) return NULL; 
            if(!a) a=headB;
            if(!b) b=headA;
        }
        return a;


        // ListNode *d1=headA;
        // ListNode *d2=headB;
        // while(d1!=d2){
        //     d1=d1==NULL?headB:d1->next;
        //     d2=d2==NULL?headA:d2->next;
        // }
        // return d1;
    }
};