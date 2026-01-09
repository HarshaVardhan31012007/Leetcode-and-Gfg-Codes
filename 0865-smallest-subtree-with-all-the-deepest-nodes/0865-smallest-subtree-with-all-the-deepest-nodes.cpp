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
    // pair<TreeNode*,int>solve(TreeNode* root){
    //     if(!root) return {NULL,INT_MIN};
    //     if(!root->left&&!root->right) return {root,0};
    //     auto l=solve(root->left);
    //     auto r=solve(root->right);
    //     if(r.second==l.second)
    //     return {root,l.second+1};
    //     else if(l.second<r.second)
    //     return {r.first,r.second+1};
    //     else
    //     return {l.first,l.second+1};
    // }
    // TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    //     auto ans=solve(root);
    //     return ans.first;
    // }


    TreeNode* ans;
    int maxi=INT_MIN;
    int solve(TreeNode* root,int d){
        if(!root){
            maxi=max(maxi,d);
            return d;
        }
        auto l=solve(root->left,d+1);
        auto r=solve(root->right,d+1);
        if(l==maxi&&r==maxi) ans=root;
        return max(l,r);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        solve(root,0);
        return ans;
    }
};