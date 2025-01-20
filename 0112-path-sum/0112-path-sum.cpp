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
    bool solve(TreeNode* root, int target,int sum){
         //checking if empty or not
         if(root==NULL){
            return false;
        }
        //i not empty check for pathsum if it is leaf node
        sum=sum+root->val;
        if(root->left==NULL&&root->right==NULL){
            if(sum==target){
                return true;
            }
            return false;
        }
        bool leftans=solve(root->left,target,sum);
        bool rightans=solve(root->right,target,sum);
         return leftans||rightans;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        // //cghecking if empty or not
        //  if(root==NULL){
        //     return false;
        // }
        // //i not empty check for sum if it is leaf node
        // if(root->left==NULL&&root->right==NULL){
        //     if(targetSum-root->val==0){
        //         return true;
        //     }
        //     return false;
        // }
        // bool leftans=hasPathSum(root->left,targetSum-root->val);
        // bool rightans=hasPathSum(root->right,targetSum-root->val);
        // return leftans||rightans;


        int sum=0;
        return solve(root,targetSum,sum);
    }
};