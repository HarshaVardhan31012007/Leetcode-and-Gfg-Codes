/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // void postorder(TreeNode* root,vector<int>&ans){
    //     if(!root) return;
    //     postorder(root->left,ans);
    //     postorder(root->right,ans);
    //     ans.push_back(root->val);
    // }
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int>ans;
    //     postorder(root,ans);
    //     return ans;
    // }


    
    vector<int> postorderTraversal(TreeNode* root) {
        // stack<TreeNode*>st;
        // TreeNode* curr=root;
        // vector<int>ans;
        // while(curr||!st.empty()){
        //     if(curr){
        //         st.push(curr);
        //         curr=curr->left;
        //     }
        //     else{
        //         TreeNode* temp=st.top()->right;
        //         if(temp){
        //            curr=temp;
        //         }
        //         else{
        //            temp=st.top();
        //            st.pop();
        //            ans.push_back(temp->val);
        //            while(!st.empty()&&st.top()->right==temp){
        //               temp=st.top();
        //               st.pop();
        //               ans.push_back(temp->val);
        //            }
        //         }
        //     }
        // }
        //  return ans;




        stack<TreeNode*>st;
        vector<int>ans;
        if(!root) return ans;
        while(root){
            st.push(root);
            root=root->left;
        }
        while(!st.empty()){
            auto node=st.top()->right;
            if(!node){
                TreeNode* temp=st.top();
                st.pop();
                ans.push_back(temp->val);
                while(!st.empty()&&st.top()->right==temp){
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->val);
                }
            }
            while(node){
                st.push(node);
                node=node->left;
            }
        }
        return ans;
    }
};