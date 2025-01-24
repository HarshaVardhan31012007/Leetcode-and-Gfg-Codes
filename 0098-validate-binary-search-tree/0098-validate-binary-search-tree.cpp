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
    bool solve(TreeNode *root,long mini,long maxi){
        if(root==NULL){
            return true;
        }
        bool currans=root->val>mini&&root->val<maxi;
        if(currans==false){
            return false;
        }
        bool leftans=solve(root->left,mini,root->val);
        bool rightans=solve(root->right,root->val,maxi);
        //no need to check currans 
        //agar yahi tak reach then curr ans is true
        return leftans&&rightans;
    }
    bool isValidBST(TreeNode* root) {
        long mini=LONG_MIN;
        long maxi=LONG_MAX;
        return solve(root,mini,maxi);
    }
};