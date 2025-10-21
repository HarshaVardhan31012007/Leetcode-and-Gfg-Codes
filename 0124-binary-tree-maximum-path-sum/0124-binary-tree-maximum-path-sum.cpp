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
    int maxi;
    int solve(TreeNode* root){
        if(!root) return 0;
        if(!root->left&&!root->right) {
            maxi=max(maxi,root->val);
            return root->val;
        }
        int l=solve(root->left);
        int r=solve(root->right);
        maxi=max(maxi,l+root->val+r);
        // if(root->left)
        // maxi=max(maxi,l);
        // if(root->right)
        // maxi=max(maxi,r);
        int nextr=root->val+max({l,r,0});
        maxi=max(maxi,nextr);
        return nextr;
    }
    int maxPathSum(TreeNode* root) {
        maxi=INT_MIN;
        maxi=max(maxi,solve(root));
        return maxi;
    }
};