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
    void solve(TreeNode* root,TreeNode* &f,TreeNode* &s,TreeNode* &prev){
        if(!root) return;
        solve(root->left,f,s,prev);
        if(prev&&prev->val>root->val){
             if(!f) f=prev;
             s=root;
        }
        prev=root;
        solve(root->right,f,s,prev);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* f=0,*s=0,*prev=0;
        solve(root,f,s,prev);
        swap(f->val,s->val);
    }
};