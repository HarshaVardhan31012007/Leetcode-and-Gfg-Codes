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
    // void solve(TreeNode *root,int &len,int step){
    //     if(root==NULL){
    //         len=max(len,step);
    //         return;
    //     }
    //     solve(root->left,len,step+1);
    //     solve(root->right,len,step+1);
    // }

     int solve(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        int leftans=solve(root->left);
        int rightans=solve(root->right);
        int finalans=max(leftans,rightans)+1;
        return finalans;
    }

    int maxDepth(TreeNode* root) {
        // int len=INT_MIN;
        // int step=0;
        // solve(root,len,step);
        // return len;

        return solve(root);
    }
};