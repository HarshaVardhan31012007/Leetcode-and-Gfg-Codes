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
    // int ans=0;
    // void solve(TreeNode* root,int &k){
    //     if(!root) return;
    //     solve(root->left,k);
    //     if(k>0){
    //         k--;
    //         if(k==0){
    //         ans=root->val;
    //         return;
    //         }
    //     }
    //     solve(root->right,k);
    // }
    // int kthSmallest(TreeNode* root, int k) {
    //    solve(root,k);
    //    return ans;
    // }


    int ans=0;
    void solve(TreeNode* root,int &k,int &count){
        if(!root) return;
        solve(root->left,k,count);
        count++;
        if(count==k){
            ans=root->val;
            return;
        }
        solve(root->right,k,count);
    }
    int kthSmallest(TreeNode* root, int k) {
       int count=0;
       solve(root,k,count);
       return ans;
    }
};