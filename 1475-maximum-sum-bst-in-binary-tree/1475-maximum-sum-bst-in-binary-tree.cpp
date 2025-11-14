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
    class Info{
       public:
       int mini;
       int maxi;
       bool isBST;
       int sum;
    };
    int ans;
    Info solve(TreeNode* root){
        if(!root) return {INT_MAX,INT_MIN,true,0};
        //no need
        // if(!root->left&&!root->right) {
        //     ans=max(ans,root->val);
        //     return {root->val,root->val,true,root->val};
        // }
        auto l=solve(root->left);
        auto r=solve(root->right);
        if(root->val>l.maxi&&root->val<r.mini&&l.isBST&&r.isBST){
            Info curr;
            curr.mini=min(root->val,l.mini);//because left may be null then root should be taken 
            curr.maxi=max(root->val,r.maxi);//because right may be null then root shiuld be answer
            curr.sum=root->val+l.sum+r.sum;
            ans=max(ans,curr.sum);
            curr.isBST=true;
            return curr;
        }
        return {0,0,false,0};
    }
    int maxSumBST(TreeNode* root) {
       ans=0;//empty bst
       solve(root);
       return ans;
    }
};