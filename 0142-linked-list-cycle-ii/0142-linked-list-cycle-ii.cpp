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
         unordered_map<ListNode*,bool>mpp;
         ListNode *temp=head;
        while(temp!=NULL){
            if(mpp[temp]==true){
                return temp;
            }
            mpp[temp]=true;
            temp=temp->next;
        }
        return nullptr; 
    }
};