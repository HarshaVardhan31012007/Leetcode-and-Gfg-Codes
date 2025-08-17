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
// class Solution {
// public:
//     bool checkpalindrome(vector<int>&ans){
//         int i=0;
//         int j=ans.size()-1;
//         while(i<j){
//             if(ans[i]!=ans[j])
//             return false;
//             i++;
//             j--;
//         }
//         return true;
//     }
//     bool isPalindrome(ListNode* head) {
//         vector<int>ans;
//         ListNode *temp=head;
//         while(temp!=NULL){
//             ans.push_back(temp->val);
//             temp=temp->next;
//         }
//         return checkpalindrome(ans);
//     }
// };





class Solution {
public:
    ListNode* reverseLL(ListNode*& prev,ListNode*& curr){
        while(curr!=NULL){
            ListNode* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    ListNode* findmiddle(ListNode* head,ListNode*& middleNodeKaPrev){
        ListNode* s=head;
        ListNode* f=head;
        while(f&&f->next){
            f=f->next->next;
            middleNodeKaPrev=s;
            s=s->next;
        }
        return s;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL) return true;
        ListNode* firstHalfHead=head;
        ListNode* middleNodeKaPrev=NULL;
        ListNode* middle=findmiddle(head,middleNodeKaPrev);
        middleNodeKaPrev->next=NULL;
        ListNode* prev=NULL;
        ListNode* curr=middle;
        ListNode* secondHalfHead=reverseLL(prev,curr);
        ListNode* temp1=firstHalfHead;
        ListNode* temp2=secondHalfHead;
        while(temp1!=NULL){
             if(temp1->val!=temp2->val)
             return false;
             else{
                temp1=temp1->next;
                temp2=temp2->next;
             }
        }
        return true;
    }
};