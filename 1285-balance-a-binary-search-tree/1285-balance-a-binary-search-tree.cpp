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
    void build(vector<TreeNode*>&v,TreeNode* root){
        if(!root) return;
        build(v,root->left);
        v.push_back(root);
        build(v,root->right);
    }
    TreeNode* solve(vector<TreeNode*>&v,int s,int e){
        if(s>e) return NULL;
        int mid=(s+e)/2;
        TreeNode* root=v[mid];
        root->left=solve(v,s,mid-1);
        root->right=solve(v,mid+1,e);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*>v;
        build(v,root);
        return solve(v,0,v.size()-1);
    }
};