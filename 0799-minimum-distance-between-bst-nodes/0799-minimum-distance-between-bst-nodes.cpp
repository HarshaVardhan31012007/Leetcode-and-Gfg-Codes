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
    int minDiffInBST(TreeNode* root) {
         vector<int>inorder;
        buildinorder(root,inorder);
        int prev=inorder[0];
        int diff=INT_MAX;
        for(int i=1;i<inorder.size();i++){
           int currdiff=inorder[i]-prev;
           diff=min(diff,currdiff);
           prev=inorder[i];
        } 
        return diff;
    }
};