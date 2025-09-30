/**
 * Definition for a binary tree Node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     if(root==NULL) return NULL;
    //     if(root==p||root==q) return root;
    //     TreeNode* l=lowestCommonAncestor(root->left,p,q);
    //     TreeNode* r=lowestCommonAncestor(root->right,p,q);
    //     if(l!=NULL&&r!=NULL)
    //     return root;
    //     else if(l!=NULL){
    //         return l;
    //     }
    //     else if(r!=NULL){
    //         return r;
    //     }
    //     return NULL;
    // }
   

    bool check(TreeNode* root,TreeNode* t){
        if(!root) return 0;
        return root==t||check(root->left,t)||check(root->right,t);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p||root==q) return root;
        bool flag=check(root->left,p);
        bool flag1=check(root->left,q);
        if(flag&&flag1) return lowestCommonAncestor(root->left,p,q);
        else if(!flag&&!flag1) return lowestCommonAncestor(root->right,p,q);
        return root;
    }
};