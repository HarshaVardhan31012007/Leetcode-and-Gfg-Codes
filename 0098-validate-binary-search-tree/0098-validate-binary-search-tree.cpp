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
    //checking from bottom


    // class Info{
    //     public:
    //     long int mini;
    //     long int maxi;
    //     bool isBST;
    // };
    // Info solve(TreeNode* root){
    //     if(!root) return {LONG_MAX,LONG_MIN,true};
    //     Info l=solve(root->left);
    //     Info r=solve(root->right);
    //     if(root->val>l.maxi&&root->val<r.mini&&l.isBST&&r.isBST){
    //         Info curr;
    //         curr.mini=min((long)root->val,l.mini);
    //         curr.maxi=max((long)root->val,r.maxi);
    //         curr.isBST=true;
    //         return curr;
    //     }
    //     return {LONG_MAX,LONG_MIN,false};
    // }
    // bool isValidBST(TreeNode* root) {
    //     return solve(root).isBST;
    // }



    //checking from top
    // bool isValidBST(TreeNode* root,long int mini=LONG_MIN,long int maxi=LONG_MAX) {
    //      if(!root) return true;
    //      if(root->val>mini&&root->val<maxi){
    //           bool l=isValidBST(root->left,mini,root->val);
    //           if(!l)
    //           return false;
    //           bool r=isValidBST(root->right,root->val,maxi);
    //           if(!r)
    //           return false;
    //           return true;
    //      }
    //      return false;
    // }

    bool isValidBST(TreeNode* root,long int mini=LONG_MIN,long int maxi=LONG_MAX) {
            if(!root) return true;
            bool flag=root->val>mini&&root->val<maxi;
            if(!flag) return false;
            bool l=isValidBST(root->left,mini,root->val);
            bool r=isValidBST(root->right,root->val,maxi);
            return l&&r;
         }
};