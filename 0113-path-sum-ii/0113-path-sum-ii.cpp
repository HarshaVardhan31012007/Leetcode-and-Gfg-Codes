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
    void solve(TreeNode *root,int target,int sum,vector<int>path,vector<vector<int>>&ans){
        if(root==NULL){
            return;
        }
        sum=sum+root->val;
        path.push_back(root->val);
        if(root->left==NULL&&root->right==NULL){
            if(sum==target){
                ans.push_back(path);
            }
            return;
        }
        solve(root->left,target,sum,path,ans);
        solve(root->right,target,sum,path,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>path;
        int sum=0;
        solve(root,targetSum,sum,path,ans);
        return ans;
    }
};