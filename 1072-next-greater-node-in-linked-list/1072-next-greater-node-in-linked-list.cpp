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


    // void solve(ListNode* head,int &len,stack<int>&st,vector<int>&greater){
    //     if(!head) return;
    //     len++;
    //     solve(head->next,len,st,greater);
    //         while(!st.empty()&&st.top()<=head->val){
    //             st.pop();
    //         }
    //         if(st.empty()){
    //         if(greater.size()==0)
    //         greater.resize(len);
    //         greater[len-1]=0;
    //         }
    //         else{
    //         greater[len-1]=st.top();
    //         }
    //         len--;
    //     st.push(head->val);
    // }
    // vector<int> nextLargerNodes(ListNode* head) {
    //     vector<int>ans;
    //     vector<int>greater;
    //     int len=0;
    //     stack<int>st;
    //     solve(head,len,st,greater);
    //     return greater;
    // }


    // vector<int> nextLargerNodes(ListNode* head) {
    //     vector<int>arr;
    //     ListNode* temp=head;
    //     while(temp){
    //        arr.push_back(temp->val);
    //        temp=temp->next;
    //     }
    //     stack<int>st;
    //     vector<int>ans(arr.size());
    //     for(int i=arr.size()-1;i>=0;i--){
    //         while(!st.empty()&&st.top()<=arr[i]) 
    //         st.pop();
    //         if(st.empty())
    //         ans[i]=0;
    //         else
    //         ans[i]=st.top();
    //         st.push(arr[i]);
    //     }
    //     return ans;


    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>arr;
        ListNode* temp=head;
        while(temp){
           arr.push_back(temp->val);
           temp=temp->next;
        }
        stack<int>st;
        vector<int>ans(arr.size());
        for(int i=0;i<arr.size();i++){
           while(!st.empty()&&arr[i]>arr[st.top()]){
            int idx=st.top();
            ans[idx]=arr[i];
            st.pop();
           }
           st.push(i);
        }
        return ans;
    }
};