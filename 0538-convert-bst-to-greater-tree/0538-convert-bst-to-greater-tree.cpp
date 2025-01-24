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
    void buildtree(TreeNode *root,vector<int>&inorder,int &i){
        if(root==NULL){
            return;
        }
        buildtree(root->left,inorder,i);
        root->val=inorder[i++];
        buildtree(root->right,inorder,i);
    }
    void buildinorder(TreeNode *root,vector<int>&inorder){
        if(root==NULL){
            return;
        }
        buildinorder(root->left,inorder);
        inorder.push_back(root->val);
        buildinorder(root->right,inorder);
    }
    TreeNode* convertBST(TreeNode* root) {
        vector<int>inorder;
        buildinorder(root,inorder);
        //int sum=0;
        for(int i=inorder.size()-1;i>=0;i--){
            // sum=sum+inorder[i];
            // inorder[i]=sum;
            int curr=inorder[i];
            int next=0;
            if(i+1<inorder.size()){
                next=inorder[i+1];
            }
            int sum=curr+next;
            inorder[i]=sum;
        } 
        int i=0;
        buildtree(root,inorder,i);
        return root;
    }
};