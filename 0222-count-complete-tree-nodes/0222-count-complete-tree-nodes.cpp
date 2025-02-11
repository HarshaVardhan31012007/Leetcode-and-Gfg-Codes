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
    int findlh(TreeNode *root){
        int c=0;
        while(root){
            c++;
            root=root->left;
        }
        return c;
    }
    int findrh(TreeNode *root){
        int c=0;
        while(root){
            c++;
            root=root->right;
        }
        return c;
    }
    int countNodes(TreeNode* root) {
       if(!root) return 0;
       int lh=findlh(root);
       int rh=findrh(root);
       if(lh==rh) return (1<<lh)-1;
       int l=countNodes(root->left);
       int r=countNodes(root->right);
       return 1+l+r;
    }
};