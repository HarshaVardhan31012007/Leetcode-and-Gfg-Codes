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
    // unordered_map<int,int>mpp;
    // bool solve(TreeNode* root,int k){
    //     if(!root) return 0;
    //     if(mpp.count(k-root->val))
    //     return true;
    //     mpp[root->val]++;
    //     bool  l=solve(root->left,k);
    //     if(l) return true;
    //     bool r=solve(root->right,k);
    //     if(r) return true;
    //     return false;
    // }
    // bool findTarget(TreeNode* root, int k) {
    //     return solve(root,k);
    // }



   
    void build(TreeNode* root,vector<int>&inorder){
        if(!root) return;
        build(root->left,inorder);
        inorder.push_back(root->val);
        build(root->right,inorder);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        build(root,inorder);
        int i=0;
        int j=inorder.size()-1;
        while(i<j){
            if(inorder[i]+inorder[j]==k) return true;
            else if(inorder[i]+inorder[j]<k){
                i++;
            }
            else
            j--;
        }
        return false;
    }
};