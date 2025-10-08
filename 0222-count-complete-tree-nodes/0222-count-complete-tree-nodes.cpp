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
    int solve(TreeNode* root,int idx){
        if(!root) return INT_MIN;
        if(!root->left&&!root->right) return idx;
        int l=solve(root->left,2*idx);
        int r=solve(root->right,2*idx+1);
        return max(l,r);
    }
    int countNodes(TreeNode* root) {
        int idx=1;
        int ans=solve(root,idx);
        return ans==INT_MIN?0:ans;
    }
};