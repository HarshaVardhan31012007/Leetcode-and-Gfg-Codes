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
    ListNode *detectCycle(ListNode *head) {
        // unordered_set<ListNode*>st;
        // ListNode* temp=head;
        // while(temp!=NULL){
        //     if(st.find(temp)!=st.end()) return  temp;
        //     st.insert(temp);
        //     temp=temp->next;
        // }
        // return NULL;


        if(!head||!head->next) return NULL;
        ListNode* s=head;ListNode* f=head;
        while(f&&f->next){
            s=s->next;
            f=f->next->next;
            if(s==f) break;
        }
        if(s!=f) return NULL;
        s=head;
        while(s!=f){
            s=s->next;
            f=f->next;
        }
        return s;
    }
};