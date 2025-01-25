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
    void solve(TreeNode *root,TreeNode *&prev,TreeNode *&f,TreeNode *&l){
    if(root==NULL){
        return;
    }
    solve(root->left,prev,f,l);
    if(prev&&prev->val>root->val){
        if(!f){
            f=prev;
        }
        l=root;
    }
    prev=root;
    solve(root->right,prev,f,l);
    }
    void recoverTree(TreeNode* root) {
       TreeNode *f=NULL;
       TreeNode *l=NULL;
       TreeNode *prev=NULL;
       solve(root,prev,f,l);
       swap(f->val,l->val);
    }
};