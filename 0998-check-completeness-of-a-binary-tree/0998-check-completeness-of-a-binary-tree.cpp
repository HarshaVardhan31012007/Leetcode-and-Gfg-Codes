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
    int count(TreeNode *root){
        if(root==NULL) return 0;
        return 1+count(root->left)+count(root->right);
    }
    bool isCBT(TreeNode *root,int index,int total){
        if(root==NULL)return true;
        if(index>total) return false;
        return isCBT(root->left,2*index,total)&&isCBT(root->right,2*index+1,total);
    }
    bool isCompleteTree(TreeNode* root) {
        int total=count(root);
        int index=1;
        return isCBT(root,index,total);
    }
};