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
    // ListNode *findmiddle(ListNode*&middlekaprev,ListNode *head){
    // ListNode *slow=head;
    // ListNode *fast=head;
    // while(fast!=NULL){
    //     fast=fast->next;
    //     if(fast!=NULL){
    //         fast=fast->next;
    //         middlekaprev=slow;
    //         slow=slow->next;
    //     }
    // }
    //    return slow;
    // }
    // ListNode *reverselist(ListNode *prev,ListNode *curr){
    //    while(curr!=NULL){
    //     ListNode* forward=curr->next;
    //     curr->next=prev;
    //     prev=curr;
    //     curr=forward;
    //    }
    //    return prev;
    // }

    bool checkpalindrome(vector<int>&ans){
        int i=0;
        int j=ans.size()-1;
        while(i<j){
            if(ans[i]!=ans[j])
            return false;
            i++;
            j--;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        vector<int>ans;
        ListNode *temp=head;
        while(temp!=NULL){
            ans.push_back(temp->val);
            temp=temp->next;
        }
        return checkpalindrome(ans);
        //method 2
        // //empty list
        // if(head==NULL)
        // return true;
        // //single node
        // if(head->next==NULL)
        // return true;
        // //find middle and prev
        // ListNode *middlekaprev=NULL;
        // ListNode *middle=findmiddle(middlekaprev,head);
        // //break;
        // middlekaprev->next=NULL;
        // ListNode* prev=NULL;
        // ListNode *curr=middle;
        // ListNode* temphead2=reverselist(prev,curr);
        // ListNode*temphead1=head;
        // while(temphead1!=NULL){
        //     if(temphead1->val!=temphead2->val){
        //         return false;
        //     }
        //     else{
        //         temphead1=temphead1->next;
        //         temphead2=temphead2->next;
        //     }
        // }
        // return true;
    }
};