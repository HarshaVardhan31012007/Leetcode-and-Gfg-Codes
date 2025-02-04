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
    // void build(vector<int>&ans,TreeNode *root){
    //     if(root==NULL){
    //         return;
    //     }
    //     ans.push_back(root->val);
    //     build(ans,root->left);
    //     build(ans,root->right);
    // }
    // void create(TreeNode *&r,vector<int>&ans,int i,int n){
    //     if(i<n){
    //         r=new TreeNode(ans[i]);
    //         create(r->right,ans,i+1,n);
    //     }
    // }
    // void flatten(TreeNode* root) {
    //     vector<int>ans;
    //     build(ans,root);
    //     TreeNode *r=NULL;
    //     int i=0;
    //     int n=ans.size();
    //     create(r,ans,i,n);
    //     return r;
    // }


    //  void build(vector<TreeNode*>&ans,TreeNode *root){
    //     if(root==NULL){
    //         return;
    //     }
    //     ans.push_back(root);
    //     build(ans,root->left);
    //     build(ans,root->right);
    // }
    //  void flatten(TreeNode* root) {
    //     //no need
    //     // if(root==NULL||!root->left&&!root->right){
    //     //     return;
    //     // }
    //     vector<TreeNode*>ans;
    //     build(ans,root);
    //     TreeNode *curr=root;
    //     for(int i=0;i<ans.size();i++){
    //         curr=ans[i];
    //         if(i+1<ans.size()){
    //             curr->left=NULL;
    //             curr->right=ans[i+1];
    //         }
    //     }
    //     //for last in original both left and right are NUll
    // }


    void flatten(TreeNode *root){
        TreeNode *curr=root;
        while(curr){
            if(curr->left){
                TreeNode *pred=curr->left;
                while(pred->right){
                    pred=pred->right;
                }
                pred->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }
};