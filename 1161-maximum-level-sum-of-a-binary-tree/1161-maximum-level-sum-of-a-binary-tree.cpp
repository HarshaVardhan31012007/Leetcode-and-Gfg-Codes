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
    // int maxLevelSum(TreeNode* root) {
    //     queue<TreeNode*>q;
    //     int sum=INT_MIN;int level=1;int ans=0;
    //     if(root)
    //     q.push(root);
    //     while(!q.empty()){
    //         int size=q.size();int csum=0;
    //         for(int i=0;i<size;i++){
    //             auto front=q.front();
    //             q.pop();
    //             csum+=front->val;
    //             if(front->left)
    //             q.push(front->left);
    //             if(front->right)
    //             q.push(front->right);
    //         }
    //         if(csum>sum){
    //             sum=csum;
    //             ans=level;
    //         }
    //         level++;
    //     }
    //     return ans;
    // }



    void solve(TreeNode* root,int level,map<int,int>&mpp){
        if(!root) return;
        mpp[level]+=root->val;
        solve(root->left,level+1,mpp);
        solve(root->right,level+1,mpp);
    }
    int maxLevelSum(TreeNode* root) {
      map<int,int>mpp;
      solve(root,0,mpp);
      int ans=0;int maxi=INT_MIN;
      for(auto &each:mpp){
        if(each.second>maxi){
            maxi=each.second;
            ans=each.first+1;
        }
      }
      return ans;
    }
};