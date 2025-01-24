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
    // void buildinorder(TreeNode *root,vector<int>&inorder){
    //     if(root==NULL){
    //         return;
    //     }
    //     buildinorder(root->left,inorder);
    //     inorder.push_back(root->val);
    //     buildinorder(root->right,inorder);
    // }

     void traverse(TreeNode *root,int &count,int k,int &ans){
        if(root==NULL){
            return;
        }
        traverse(root->left,count,k,ans);
        count++;
        if(count==k){
            ans=root->val;
            return;
        }
        traverse(root->right,count,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        // vector<int>inorder;
        // buildinorder(root,inorder);
        // return inorder[k-1];
        int count=0;
        int ans=-1;
        traverse(root,count,k,ans);
        return ans;
    }
};