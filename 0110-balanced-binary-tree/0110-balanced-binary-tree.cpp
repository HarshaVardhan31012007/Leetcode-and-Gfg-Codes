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
// bool isbalanced=true;
// int height(TreeNode *root){
//     if(!root)return 0;
//     int lh=height(root->left);
//     int rh=height(root->right);
//     if(isbalanced&&abs(lh-rh)>1){
//         isbalanced=false;
//     }
//     return max(lh,rh)+1;
// }
//     bool isBalanced(TreeNode* root) {
//         height(root);
//         return isbalanced;
//     }
     
      pair<bool,int>solve(TreeNode *root){
         if(root==NULL){
           pair<bool,int>p=make_pair(true,0);
           return p;
        }
        pair<bool,int>left=solve(root->left);
        pair<bool,int>right=solve(root->right);
        pair<bool,int>ans;
        ans.first=left.first&&right.first&&abs(left.second-right.second)<=1;
        ans.second=max(left.second,right.second)+1;
        return ans;
      }
      bool isBalanced(TreeNode *root){
        pair<bool,int>ans=solve(root);
        return ans.first;
      }
};