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
    int solve(TreeNode *root,int &cameras){
        if(!root) return 1;
        int l=solve(root->left,cameras);
        int r=solve(root->right,cameras);
        if(l==0||r==0){
            cameras++;
            return 2;
        }
        if(l==2||r==2){
            return 1;
        }
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        int cameras=0;
        int rootstate=solve(root,cameras);
        if(rootstate==0){
            cameras++;
        }
        return cameras;
    }
};