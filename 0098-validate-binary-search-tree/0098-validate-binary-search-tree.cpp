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
    class Info{
        public:
        long int mini;
        long int maxi;
        bool isBST;
    };
    Info solve(TreeNode* root){
        if(!root) return {LONG_MAX,LONG_MIN,true};
        Info l=solve(root->left);
        Info r=solve(root->right);
        if(root->val>l.maxi&&root->val<r.mini&&l.isBST&&r.isBST){
            Info curr;
            curr.mini=min((long)root->val,l.mini);
            curr.maxi=max((long)root->val,r.maxi);
            curr.isBST=true;
            return curr;
        }
        return {LONG_MAX,LONG_MIN,false};
    }
    bool isValidBST(TreeNode* root) {
        return solve(root).isBST;
    }
};