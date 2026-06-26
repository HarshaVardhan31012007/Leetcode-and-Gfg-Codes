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
    // bool isSame(TreeNode* root,TreeNode* root1){
    //     if(!root&&!root1) return true;
    //     if(!root||!root1) return false;
    //     if(root->val!=root1->val) return false;
    //     return isSame(root->left,root1->left)&&isSame(root->right,root1->right);
    // }
    // bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    //     if(!root) return false;
    //     if(root->val==subRoot->val){
    //         if(isSame(root,subRoot))
    //         return true;
    //     }
    //     return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    // }


    string solve(TreeNode* subRoot){
        if(!subRoot) return "NULL";
        return to_string(subRoot->val)+" "+solve(subRoot->left)+" "+solve(subRoot->right);
    }
    string check(TreeNode* root,string &subtree,bool &ans){
        if(!root) return "NULL";
        string temp=(to_string(root->val)+" "+check(root->left,subtree,ans)+" "+check(root->right,subtree,ans));
        if(!ans&&temp==subtree) ans=true;
        return temp;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string subtree=solve(subRoot);
        bool ans=false;
        check(root,subtree,ans);
        return ans;
    }
};