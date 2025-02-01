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
    bool isMirror(TreeNode* p, TreeNode* q) {
        if(!p&&!q) return true;
        if(p&&q){
             return p->val==q->val&&isMirror(p->left,q->right)&&isMirror(p->right,q->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        //this is nedded if min no of nodes are zer0
        // if(root==NULL){
        //     return true;
        // }
        return isMirror(root->left,root->right);
    }
};