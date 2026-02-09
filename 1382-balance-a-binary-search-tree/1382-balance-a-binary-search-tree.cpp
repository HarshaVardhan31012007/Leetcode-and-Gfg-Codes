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
    void inorder(TreeNode* root,vector<int>&inorderv){
        if(!root) return;
        inorder(root->left,inorderv);
        inorderv.push_back(root->val);
        inorder(root->right,inorderv);
    }
    TreeNode* solve(vector<int>&inorderv,int s,int e){
        if(s>e) return NULL;
        int mid=(s+e)/2;
        TreeNode* root=new TreeNode(inorderv[mid]);
        root->left=solve(inorderv,s,mid-1);
        root->right=solve(inorderv,mid+1,e);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorderv;
        inorder(root,inorderv);
        TreeNode* ans=solve(inorderv,0,(int)inorderv.size()-1);
        return ans;
    }
};