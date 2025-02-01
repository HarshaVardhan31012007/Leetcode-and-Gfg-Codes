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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // if(!p&&!q) return true;
        // // if(!p&&q) return false;
        // // if(p&&!q) return false; 
        // if(!p^!q) return false;// it works because we are using it for integers 0 and 1 not for pointers 
        // //p^q will come error
        // bool curr=p->val==q->val;
        // if(curr==false){
        //     return false;
        // }
        // bool l=isSameTree(p->left,q->left);
        // bool r=isSameTree(p->right,q->right);
        // return l&&r;

        if(!p&&!q) return true;
        if(p&&q){
             return p->val==q->val&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
        }
        return false;
    }
};