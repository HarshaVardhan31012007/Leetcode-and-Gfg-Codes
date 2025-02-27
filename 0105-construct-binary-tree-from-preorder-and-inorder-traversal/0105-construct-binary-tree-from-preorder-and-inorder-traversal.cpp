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
    int find(vector<int>&inorder,int is,int ie,int k){
       for(int i=is;i<=ie;i++){
        if(inorder[i]==k){
            return i;
        }
       }
       return -1;
    }
    //unordered_map<int,int>mpp;
    TreeNode* build(vector<int>&preorder,vector<int>&inorder,int &pi,int is,int ie){
        if(pi>=preorder.size()){
            return NULL;
        }
        if(is>ie){
            return NULL;
        }
        TreeNode *root=new TreeNode(preorder[pi]);
        int index=find(inorder,is,ie,preorder[pi]);
        //int index=mpp[preorder[pi]];
        pi++;
        root->left=build(preorder,inorder,pi,is,index-1);
        root->right=build(preorder,inorder,pi,index+1,ie);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // for(int i=0;i<inorder.size();i++){
        //     mpp[inorder[i]]=i;
        // }
        int i=0;
        return build(preorder,inorder,i,0,inorder.size()-1);
    }
};