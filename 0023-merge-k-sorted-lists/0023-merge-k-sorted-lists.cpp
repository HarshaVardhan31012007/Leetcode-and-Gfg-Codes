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
    class comp{
        public:
        bool operator()(ListNode* &a,ListNode* &b){
             return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,comp>pq;
        for(auto &list:lists){
            if(list)
            pq.push(list);
        }
        ListNode* ans=NULL;
        ListNode* it=ans;
        if(pq.size()==0) return ans;
        while(pq.size()>1){
            ListNode* top=pq.top();
            pq.pop();
            if(!ans){
                ans=top;
                it=ans;
            }
            else{
                it->next=top;
                it=it->next;
            }
            if(top->next){
                pq.push(top->next);
            }
        }
            if(!ans){
                ans=pq.top();
                it=ans;
            }
            else{
                it->next=pq.top();
                it=it->next;
            }
        return ans;
    }
};