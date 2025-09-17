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
    
    void nextGreater(ListNode* head,vector<int>&ans,stack<int>&st){
        if(!head) return;
        nextGreater(head->next,ans,st);
        while(st.top()<=head->val)
        st.pop();
        if(st.top()==INT_MAX)
        ans.push_back(0);
        else
        ans.push_back(st.top());
        st.push(head->val);
    }
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ans;
        stack<int>st;
        st.push(INT_MAX);
        nextGreater(head,ans,st);
        return vector(ans.rbegin(),ans.rend());
    }
};