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
    // bool issumtree=true;
    // int sum(TreeNode *root){
    //     if(!root) return 0;
    //     if(root->left==NULL&&root->right==NULL){
    //         return root->val;
    //     }
    //     int l=sum(root->left);
    //     int r=sum(root->right);
    //     if(issumtree&&(l+r)!=root->val){
    //         issumtree=false;
    //     }
    //     return l+r+root->val;
    // }
    // bool checkTree(TreeNode* root) {
    //     sum(root);
    //     return issumtree;
    // }
    
    pair<bool,int>solve(TreeNode *root){
        if(!root) return {true,0};
        if(!root->left&&!root->right) return {true,root->val};
        pair<bool,int>l=solve(root->left);
        pair<bool,int>r=solve(root->right);
        return {l.first&&r.first&&l.second+r.second==root->val,l.second+r.second+root->val};
    }
    bool checkTree(TreeNode *root){
        pair<bool,int>ans=solve(root);
        return ans.first;
    }
};