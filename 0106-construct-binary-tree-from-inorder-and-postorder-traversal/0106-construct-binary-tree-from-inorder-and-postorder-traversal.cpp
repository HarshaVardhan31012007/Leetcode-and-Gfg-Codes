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
     unordered_map<int,int>mpp;
    TreeNode* build(vector<int>&postorder,vector<int>&inorder,int &pi,int is,int ie){
        if(pi<0){
            return NULL;
        }
        if(is>ie){
            return NULL;
        }
        TreeNode *root=new TreeNode(postorder[pi]);
        //another method to find index that is to iterate and find index
        int index=mpp[postorder[pi]];
        pi--;
        root->right=build(postorder,inorder,pi,index+1,ie);
        root->left=build(postorder,inorder,pi,is,index-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        int i=postorder.size()-1;
        return build(postorder,inorder,i,0,inorder.size()-1);
    }
};