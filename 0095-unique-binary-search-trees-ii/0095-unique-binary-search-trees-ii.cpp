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
    vector<TreeNode*>solve(int s,int e,vector<vector<vector<TreeNode*>>>&dp){
        if(s>e) return {NULL};
        if(s==e) return {new TreeNode(s)};
        if(!dp[s][e].empty()) return dp[s][e];
        vector<TreeNode*>ans;
        for(int i=s;i<=e;i++){
            vector<TreeNode*>l=solve(s,i-1,dp);
            vector<TreeNode*>r=solve(i+1,e,dp);
            for(auto &each:l){
                for(auto &el:r){
                    TreeNode* root=new TreeNode(i);
                    root->left=each;
                    root->right=el;
                    ans.push_back(root);
                }
            }
        }
        return dp[s][e]=ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<vector<TreeNode*>>>dp(n+1,vector<vector<TreeNode*>>(n+1));
        return solve(1,n,dp);
    }
};