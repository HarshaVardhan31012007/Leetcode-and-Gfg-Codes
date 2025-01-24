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
    void buildinorder(TreeNode *root,vector<int>&inorder){
        if(root==NULL){
            return;
        }
        buildinorder(root->left,inorder);
        inorder.push_back(root->val);
        buildinorder(root->right,inorder);
    }
    bool find(vector<int>&arr,int k){
        int s=0;
        int e=arr.size()-1;
        while(s<e){
            if(arr[s]+arr[e]==k){
                return true;
            }
            else if(arr[s]+arr[e]<k){
                s++;
            }
            else if(arr[s]+arr[e]>k){
                e--;
            }
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        buildinorder(root,inorder);
        bool ans=find(inorder,k);
        return ans;
    }
};