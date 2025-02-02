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
    //method 1
    // int ans=0;
    // void check(TreeNode *root,int &ans,long long int k){
    //    if(root==NULL){
    //     return;
    //    }
    //    if(k==root->val){
    //     ans=ans+1;
    //    }
    //    k=k-root->val;
    //    check(root->left,ans,k);
    //    check(root->right,ans,k);
    // }
    // int pathSum(TreeNode* root, long long int targetSum) {
    //     if(root){
    //     check(root,ans,targetSum);
    //     pathSum(root->left,targetSum);
    //     pathSum(root->right,targetSum);
    //     }
    //     return ans;
    // }

    //method 2
    void check(TreeNode *root,long long int k,int &ans,vector<int>v){
       if(root==NULL){
        return;
       }
       v.push_back(root->val);
       check(root->left,k,ans,v);
       check(root->right,k,ans,v);
       int size=v.size();
       long long int sum=0;
       for(int i=size-1;i>=0;i--){
        sum=sum+v[i];
          if(sum==k){
            ans++;
          }
       }
    }
    int pathSum(TreeNode* root, long long int targetSum) {
         int ans=0;
         vector<int>v;
         check(root,targetSum,ans,v);
        return ans;
    }
};