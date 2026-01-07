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
    typedef long long ll;
    const int mod=1e9+7;
    ll find(TreeNode* root){
        if(!root) return 0;
        return (root->val+find(root->left)+find(root->right));
    }
    ll solve(TreeNode* root,ll &maxi,ll tsum){
        if(!root) return 0;
        ll l=solve(root->left,maxi,tsum);
        ll r=solve(root->right,maxi,tsum);
        ll curr=(l+r+root->val);
        ll up=tsum-curr;
        maxi=max(maxi,(curr*up));
        return curr;
    }
    int maxProduct(TreeNode* root) {
        ll tsum=find(root);
        ll maxi=1;
        ll down=solve(root,maxi,tsum);
        return maxi%mod;
    }
};