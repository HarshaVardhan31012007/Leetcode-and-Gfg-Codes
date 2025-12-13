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
        // this is wrong because when it is becoming null at in that iteration you should move to head// here null as one case not treaten because if it isnull we are moving to head && as well as one forward two times we are moving // so incorrect
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

        // ListNode* a=headA;
        // ListNode* b=headB;// here when you see correctly whenever we get one null,in same step we are going to head so that it is treated as equal move// edge case when there is no intersection // when both null at a time that means no intersection return null
        // while(a!=b){
        //     a=a->next;
        //     b=b->next;
        //     if(a==NULL&&b==NULL) return NULL; 
        //     if(!a) a=headB;
        //     if(!b) b=headA;
        // }
        // return a;

        // in this case we are treating null as one node in our moves
        //one move only in each step
        // move to null treated as one step
        //moving from null to head is also one step
        // for each two lists,always null is an intersection 
        //we will get ans which is first intersection
        //if first intersection is null that means no intersection of lists
        // ListNode *d1=headA;
        // ListNode *d2=headB;
        // while(d1!=d2){
        //     d1=d1==NULL?headB:d1->next;
        //     d2=d2==NULL?headA:d2->next;
        // }
        // return d1;



        //equal steps

        //    ListNode* a=headA;
        //    ListNode* b=headB;
        //    while(a!=b){
        //       a=a->next;
        //       b=b->next;
        //       if(a==NULL&&b==NULL) return 0;
        //       if(a==NULL)
        //       a=headA;
        //       if(b==NULL)
        //       b=headB;
        //    }
        //    return a;


           ListNode* a=headA;
           ListNode* b=headB;
           while(a!=b){
              if(a==NULL) a=headA;
              else a=a->next;
              if(b==NULL) b=headB;
              else b=b->next;
           }
           return a;



    }
};