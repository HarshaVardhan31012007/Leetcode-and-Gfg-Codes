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
    // int prev=0;
    // TreeNode* bstToGst(TreeNode* root) {
    //     if(!root) return NULL;
    //     TreeNode* r=bstToGst(root->right);
    //     root->val+=prev;
    //     prev=root->val;
    //     TreeNode* l=bstToGst(root->left);
    //     return root;
    // }


    void build(TreeNode* root,vector<long long int>&inorder){
        if(!root) return;
        build(root->left,inorder);
        inorder.push_back(root->val);
        build(root->right,inorder);
    }
    void traverse(TreeNode* root,vector<long long int>&inorder,int &j){
        if(!root) return;
        traverse(root->left,inorder,j);
        root->val=inorder[j++];
        traverse(root->right,inorder,j);
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<long long int>inorder;
        build(root,inorder);
        for(int i=(int)inorder.size()-2;i>=0;i--){
            inorder[i]+=inorder[i+1];
        }
        int j=0;
        traverse(root,inorder,j);
        return root;
    }
};