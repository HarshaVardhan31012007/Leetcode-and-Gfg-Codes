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
    int solve(TreeNode* root,int t,unordered_map<long long,int>&visited,long long int &sum){
        if(!root) return 0;
        sum+=root->val;
        visited[sum]++;
        int l=solve(root->left,t,visited,sum);
        int r=solve(root->right,t,visited,sum);
        int curr=0;
        visited[sum]--;
        if(visited[sum-t]>0){
            curr=visited[sum-t];
        }
        if(sum==t)
        curr++;
        sum-=root->val;
        return curr+l+r;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int>visited;
        long long int sum=0;
        return solve(root,targetSum,visited,sum);
    } 
};