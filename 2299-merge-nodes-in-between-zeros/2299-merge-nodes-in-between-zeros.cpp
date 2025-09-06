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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head;
        ListNode* ans=new ListNode(-1);
        ListNode* it=ans;
        int sum=0;
        while(temp!=NULL){
            if(temp->val==0){
                if(sum!=0){
                it->next=new ListNode(sum);
                it=it->next;
                sum=0;
                }
            }
            else
            sum+=temp->val;
            temp=temp->next;
        }
        it->next=NULL;
        ListNode* finalans=ans->next;
        ans->next=NULL;
        delete ans;
        return finalans;
    }
};