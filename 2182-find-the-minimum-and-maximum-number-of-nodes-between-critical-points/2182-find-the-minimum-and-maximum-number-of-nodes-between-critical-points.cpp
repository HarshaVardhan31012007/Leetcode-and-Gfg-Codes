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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head||!head->next) return {-1,-1};
        vector<int>criticalPoints;
        ListNode* temp=head->next;
        ListNode* prev=head;
        int pos=1;
        while(temp->next!=NULL){
            if(prev->val<temp->val&&temp->val>temp->next->val){
                criticalPoints.push_back(pos);
            }
            else if(prev->val>temp->val&&temp->val<temp->next->val){
               criticalPoints.push_back(pos);
            }
            pos++;
            prev=temp;
            temp=temp->next;
        }
        int mini=INT_MAX;
        int maxi=INT_MIN;
        if(criticalPoints.size()>=2)
        maxi=max(maxi,criticalPoints[criticalPoints.size()-1]-criticalPoints[0]);
        for(int i=1;i<criticalPoints.size();i++){
             int diff=criticalPoints[i]-criticalPoints[i-1];
             mini=min(mini,diff);
        }
        if(mini==INT_MAX) mini=-1;
        if(maxi==INT_MIN) maxi=-1;
        return {mini,maxi};
    }
};