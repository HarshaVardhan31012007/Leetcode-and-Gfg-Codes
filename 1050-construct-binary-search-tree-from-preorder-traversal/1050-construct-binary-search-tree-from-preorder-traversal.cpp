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
    TreeNode *solve(int &i,vector<int>& preorder,int mini,int maxi){
       if(i>=preorder.size()){
        return NULL;
       }
       TreeNode *root=nullptr;
       if(preorder[i]>mini&&preorder[i]<maxi){
        root=new TreeNode(preorder[i++]);
        root->left=solve(i,preorder,mini,root->val);
        root->right=solve(i,preorder,root->val,maxi);
       }
       return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini=INT_MIN;
        int maxi=INT_MAX;
        int i=0;
        TreeNode *root=solve(i,preorder,mini,maxi);
        return root;
    }
};