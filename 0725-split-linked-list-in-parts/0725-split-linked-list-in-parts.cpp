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
    int getLength(ListNode* head){
        int len=0;
        while(head!=NULL){
            len++;
            head=head->next;
        }
        return len;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length=getLength(head);
        int each=length/k;
        int rem=length%k;
        vector<int>size(k,each);
        for(int i=0;i<k;i++){
            if(rem>0){
            size[i]++;
            rem--;
            }
        }
        vector<ListNode*>ans;
        ListNode* temp=head;
        for(int i=0;i<size.size();i++){
            int l=size[i];
            ans.push_back(temp);
            ListNode *prev=NULL;
            while(temp!=NULL&&l--){
               prev=temp;
               temp=temp->next;
            }
            if(prev)
            prev->next=NULL;
        }
        return ans;
    }
};