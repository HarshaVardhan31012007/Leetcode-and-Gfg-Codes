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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans=new ListNode(-1);
        ListNode* it=ans;
        while(list1&&list2){
            if(list1->val<list2->val){
                it->next=list1;
                it=it->next;
                list1=list1->next;
            }
            else{
                it->next=list2;
                it=it->next;
                list2=list2->next;
            }
        }
        if(list2!=NULL)
        it->next=list2;
        if(list1!=NULL)
        it->next=list1;
        ListNode* finalans=ans->next;
        ans->next=NULL;
        delete ans;
        return finalans;
    }
};