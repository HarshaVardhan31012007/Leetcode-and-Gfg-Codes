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
    class comapre{
       public:
       bool operator()(ListNode *a,ListNode*b){
        return a->val>b->val;
       }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,comapre>pq;
        ListNode *head=NULL;
        ListNode *tail=NULL;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL)
            pq.push(lists[i]);
        }
        while(!pq.empty()){
         ListNode *top=pq.top();
         pq.pop();
         if(head==NULL&&tail==NULL){
           head=top;
           tail=top;
         }
         else{
            tail->next=top;
            tail=top;
         }
         if(tail->next!=NULL) pq.push(tail->next);
        }
        return head;
    }
};