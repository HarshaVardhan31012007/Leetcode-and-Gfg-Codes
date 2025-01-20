/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(root==p||root==q){
            return root;
        }
        TreeNode *lef=lowestCommonAncestor(root->left,p,q);
        TreeNode *righ=lowestCommonAncestor(root->right,p,q);
        if(lef==NULL&&righ==NULL){
            return NULL;
        }
         else if(lef!=NULL&&righ==NULL){
            return lef;
        }
         else if(lef==NULL&&righ!=NULL){
            return righ;
        }
        // agar up to this reach menas p and q are eual to left and right
        return root;
    }
};