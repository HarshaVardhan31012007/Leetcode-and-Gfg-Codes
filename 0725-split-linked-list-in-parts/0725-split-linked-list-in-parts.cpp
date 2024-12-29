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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int N=0;
        ListNode *temp=head;
        while(temp!=NULL){
            N++;
            temp=temp->next;
        }
        int partsize=N/k;
        int extranodes=N%k;
        temp=head;
        vector<ListNode*>ans(k,nullptr);
        for(int i=0;i<k && temp!=NULL;i++){
           ans[i]=temp;
           int currsize=partsize+((extranodes--)>0?1:0);
           for(int j=0;j<currsize-1;j++){
            temp=temp->next;
           }
           ListNode *nextSP=temp->next;
           temp->next=NULL;
           temp=nextSP;
        }
        return ans;
    }
};