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
    int findSum(TreeNode* root,int sum){
        if(!root->left&&!root->right) return sum;
        int ans=0;
        if(root->left)
        ans+=findSum(root->left,sum*2+root->left->val);
        if(root->right)
        ans+=findSum(root->right,sum*2+root->right->val);
        return ans;
    }
    int sumRootToLeaf(TreeNode* root) {
        return findSum(root,root->val);
    }
};