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
    // pair<int,int>solve(TreeNode* root){
    //     if(!root) return {0,0};
    //     if(!root->left&&!root->right) return {root->val,0};
    //     auto l=solve(root->left);
    //     auto r=solve(root->right);
    //     int inc=root->val+l.second+r.second;
    //     int exc=max(l.first,l.second)+max(r.first,r.second);
    //     return {inc,exc};
    // }
    // int rob(TreeNode* root) {
    //    auto ans=solve(root);
    //    return max(ans.first,ans.second);
    // }


    map<TreeNode*,int>mpp;
    int rob(TreeNode* root) {
        if(!root) return 0;
        if(!root->left&!root->right) return root->val;
        if(mpp.count(root)) return mpp[root];
        int inc=root->val;
        if(root->left){
            inc+=rob(root->left->left)+rob(root->left->right);
        }
        if(root->right){
            inc+=rob(root->right->left)+rob(root->right->right);
        }
        int exc=rob(root->left)+rob(root->right);
        return mpp[root]=max(inc,exc);
    }
};