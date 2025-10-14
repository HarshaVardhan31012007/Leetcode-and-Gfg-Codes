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
    string solve(TreeNode* root,unordered_map<string,TreeNode*>&subtree,vector<TreeNode*>&ans){
        if(root==NULL) return "NULL";
        string left=solve(root->left,subtree,ans);
        string right=solve(root->right,subtree,ans);
        string curr=to_string(root->val)+" "+left+" "+right;
        if(subtree.find(curr)!=subtree.end()){
            if(subtree[curr]){
            ans.push_back(root);
            subtree[curr]=NULL;
            }
        }
        else
        subtree[curr]=root;
        return curr;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>ans;
        unordered_map<string,TreeNode*>subtree;
        solve(root,subtree,ans);
        return ans;
    }
};