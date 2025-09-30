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
    // int solve(TreeNode* root,int &maxi){
    //      if(!root) return -1;
    //      int l=solve(root->left,maxi);
    //      int r=solve(root->right,maxi);
    //      maxi=max(maxi,l+r+2);
    //      return max(l,r)+1;
    // }
    // int diameterOfBinaryTree(TreeNode* root) {
    //     int maxi=INT_MIN;
    //     solve(root,maxi);
    //     return maxi;
    // }


    // int solve(TreeNode* root,int &maxi){
    //      if(!root) return 0;
    //      int l=solve(root->left,maxi);
    //      int r=solve(root->right,maxi);
    //      maxi=max(maxi,l+r);
    //      return max(l,r)+1;
    // }
    // int diameterOfBinaryTree(TreeNode* root) {
    //     int maxi=INT_MIN;
    //     solve(root,maxi);
    //     return maxi;
    // }



    int solve(TreeNode* root){
         if(!root) return 0;
         int l=solve(root->left);
         int r=solve(root->right);
         return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int l=diameterOfBinaryTree(root->left);
        int r=diameterOfBinaryTree(root->right);
        int option=solve(root->left)+solve(root->right);
        return max({l,r,option});
    }
};