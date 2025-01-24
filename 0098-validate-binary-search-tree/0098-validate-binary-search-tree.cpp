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
    void buildinorder(TreeNode *root,vector<int>&inorder){
        if(root==NULL){
            return;
        }
        buildinorder(root->left,inorder);
        inorder.push_back(root->val);
        buildinorder(root->right,inorder);
    }

    // bool solve(TreeNode *root,long mini,long maxi){
    //     // if(root==NULL){
    //     //     return true;
    //     // }
    //     // bool currans=root->val>mini&&root->val<maxi;
    //     // if(currans==false){
    //     //     return false;
    //     // }
    //     // bool leftans=solve(root->left,mini,root->val);
    //     // bool rightans=solve(root->right,root->val,maxi);
    //     // //no need to check currans 
    //     // //agar yahi tak reach then curr ans is true
    //     // return leftans&&rightans;


    //     if(root==NULL){
    //         return true;
    //     }
    //     return root->val>mini&&root->val<maxi&&solve(root->left,mini,root->val)&&solve(root->right,root->val,maxi);
    // }
    bool isValidBST(TreeNode* root) {
        // long mini=LONG_MIN;
        // long maxi=LONG_MAX;
        // return solve(root,mini,maxi);


         vector<int>inorder;
        buildinorder(root,inorder);
        int prev=inorder[0];
        for(int i=1;i<inorder.size();i++){
            int curr=inorder[i];
            if(prev>=curr){
                return false;
            }
            prev=curr;
        } 
        return true;
    }
};