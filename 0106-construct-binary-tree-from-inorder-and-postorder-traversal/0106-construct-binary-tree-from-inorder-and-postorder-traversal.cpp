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
    int find(vector<int>&v,int s,int e,int d){
        for(int i=s;i<=e;i++){
            if(v[i]==d)
            return i;
        }
        return -1;
    }
    TreeNode* build(vector<int>&postorder,vector<int>&inorder,int &i,int s,int e,unordered_map<int,int>&mpp){
        if(s>e) return NULL;
        TreeNode* root=new TreeNode(postorder[i--]);
        //int idx=find(inorder,s,e,root->val);
        int idx=mpp[root->val];
        root->right=build(postorder,inorder,i,idx+1,e,mpp);
        root->left=build(postorder,inorder,i,s,idx-1,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int j=postorder.size()-1;
        unordered_map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return build(postorder,inorder,j,0,inorder.size()-1,mpp);
    }
};