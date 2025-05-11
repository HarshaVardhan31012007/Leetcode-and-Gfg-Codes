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
    unordered_map<TreeNode*,int>dp;
    int rob(TreeNode* root) {
       if(!root) return 0;
       if(!root->left&&!root->right) return root->val;
       if(dp.find(root)!=dp.end()) return dp[root];
       int inc=root->val;
       if(root->left!=NULL)
       inc+=rob(root->left->left)+rob(root->left->right);
       if(root->right!=NULL)
       inc+=rob(root->right->left)+rob(root->right->right);
       int exc=rob(root->left)+rob(root->right);
       return dp[root]=max(inc,exc);
    }
};