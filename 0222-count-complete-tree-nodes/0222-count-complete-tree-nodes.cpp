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
    // int solve(TreeNode* root,int idx){
    //     if(!root) return INT_MIN;
    //     if(!root->left&&!root->right) return idx;
    //     int l=solve(root->left,2*idx);
    //     int r=solve(root->right,2*idx+1);
    //     return max(l,r);
    // }
    // int countNodes(TreeNode* root) {
    //     int idx=1;
    //     int ans=solve(root,idx);
    //     return ans==INT_MIN?0:ans;
    // }


    //  int solve(TreeNode* root){
    //     if(!root) return 0;
    //     if(!root->left&&!root->right) return 1;
    //     return 1+solve(root->left)+solve(root->right);
    // }
    // int countNodes(TreeNode* root) {
    //     int idx=1;
    //     return solve(root);
    // }


    int lefth(TreeNode* root){
        int count=0;
        while(root){
            count++;
            root=root->left;
        }
        return count;
    }
    int righth(TreeNode* root){
        int count=0;
        while(root){
            count++;
            root=root->right;
        }
        return count;
    }
    int countNodes(TreeNode* root) {
        int lh=lefth(root);
        int rh=righth(root);
        if(lh==rh) return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};