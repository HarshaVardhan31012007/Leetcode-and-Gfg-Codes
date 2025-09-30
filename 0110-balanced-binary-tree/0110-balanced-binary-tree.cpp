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
    int solve(TreeNode* root,bool &flag) {
        if(!root) return -1;
        int l=solve(root->left,flag);
        int r=solve(root->right,flag);
        bool flag1=abs(l-r)<=1;
        if(flag&&!flag1)
        flag=0;
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
         bool flag=1;
         solve(root,flag);
         return flag;
    }
};