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
    void sanitizeMap(ListNode* node,unordered_map<int,ListNode*>&mpp,int sum){
        int temp=sum;
        while(1){
            temp+=node->val;
            if(temp==sum) break;
            mpp.erase(temp);
            node=node->next;
        }
    }
    ListNode* removeZeroSumSublists(ListNode* head) {
        int csum=0;
        unordered_map<int,ListNode*>mpp;
        ListNode* it=head;
        while(it){
            csum+=it->val;
            if(csum==0){
                head=it->next;
                mpp.clear();
            }
            else if(mpp.find(csum)!=mpp.end()){
                sanitizeMap(mpp[csum]->next,mpp,csum);
                mpp[csum]->next=it->next;
            }
            else
            mpp[csum]=it;
            it=it->next;
        }
        return head;
    }
};