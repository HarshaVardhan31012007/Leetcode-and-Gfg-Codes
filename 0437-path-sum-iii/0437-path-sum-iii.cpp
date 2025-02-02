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
    int ans=0;
    void check(TreeNode *root,int &ans,long long int k){
       if(root==NULL){
        return;
       }
       if(k==root->val){
        ans=ans+1;
       }
       k=k-root->val;
       check(root->left,ans,k);
       check(root->right,ans,k);
    }
    int pathSum(TreeNode* root, long long int targetSum) {
        if(root){
        check(root,ans,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        }
        return ans;
    }
};