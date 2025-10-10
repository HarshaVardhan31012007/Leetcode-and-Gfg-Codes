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
    // int solve(TreeNode* root,int t,unordered_map<long long,int>&visited,long long int &sum){
    //     if(!root) return 0;
    //     sum+=root->val;
    //     visited[sum]++;
    //     int l=solve(root->left,t,visited,sum);
    //     int r=solve(root->right,t,visited,sum);
    //     int curr=0;
    //     visited[sum]--;
    //     if(visited[sum-t]>0){
    //         curr=visited[sum-t];
    //     }
    //     if(sum==t)
    //     curr++;
    //     sum-=root->val;
    //     return curr+l+r;
    // }
    // int pathSum(TreeNode* root, int targetSum) {
    //     unordered_map<long long,int>visited;
    //     long long int sum=0;
    //     return solve(root,targetSum,visited,sum);
    // } 

    
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


    int solve(TreeNode* root,int t,vector<int>&v){
        if(!root) return 0;
        v.push_back(root->val);
        int l=solve(root->left,t,v);
        int r=solve(root->right,t,v);
        int curr=0;
        long long int sum=0;
        for(int i=v.size()-1;i>=0;i--){
             sum+=v[i];
             if(sum==t)
             curr++;
        }
        v.pop_back();
        return curr+l+r;
    }
    int pathSum(TreeNode* root, long long int targetSum) {
       vector<int>v;
       return solve(root,targetSum,v);
    }
};