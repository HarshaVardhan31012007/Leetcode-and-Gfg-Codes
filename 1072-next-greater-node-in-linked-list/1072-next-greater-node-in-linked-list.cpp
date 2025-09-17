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
    
    // void nextGreater(ListNode* head,vector<int>&ans,stack<int>&st){
    //     if(!head) return;
    //     nextGreater(head->next,ans,st);
    //     while(st.top()<=head->val)
    //     st.pop();
    //     if(st.top()==INT_MAX)
    //     ans.push_back(0);
    //     else
    //     ans.push_back(st.top());
    //     st.push(head->val);
    // }
    // vector<int> nextLargerNodes(ListNode* head) {
    //     vector<int>ans;
    //     stack<int>st;
    //     st.push(INT_MAX);
    //     nextGreater(head,ans,st);
    //     return vector(ans.rbegin(),ans.rend());
    // }
    void solve(ListNode* head,int &len,stack<int>&st,vector<int>&greater){
        if(!head) return;
        len++;
        solve(head->next,len,st,greater);
        if(!head->next){
        greater.resize(len);
        greater[len-1]=0;
        len--;
        }
        else{
            while(!st.empty()&&st.top()<=head->val){
                st.pop();
            }
            if(st.empty())
            greater[len-1]=0;
            else
            greater[len-1]=st.top();
            len--;
        }
        st.push(head->val);
    }
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ans;
        vector<int>greater;
        int len=0;
        stack<int>st;
        solve(head,len,st,greater);
        return greater;
    }
};