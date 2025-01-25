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
    int getMax(TreeNode *root){
        if(root==NULL){
            return -1;
        }
        while(root->right!=NULL)
        root=root->right;
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==key){
           if(root->left==NULL&&root->right==NULL){
            delete root;
            return NULL;
           }
           else if(root->left!=NULL&&root->right==NULL){
            TreeNode *leftchild=root->left;
            root->left=NULL;
            delete root;
            return leftchild;
           }
           else if(root->left==NULL&&root->right!=NULL){
             TreeNode *rightchild=root->right;
            root->right=NULL;
            delete root;
            return rightchild;
           }
           else if(root->left!=NULL&&root->right!=NULL){
                // int maxVal=getMax(root->left);
                // root->val=maxVal;
                // root->left=deleteNode(root->left,maxVal);
                // return root;

                //inplace
                TreeNode *rightscan=root->right;
                while(rightscan->left!=NULL){
                    rightscan=rightscan->left;
                }
                 TreeNode *rc=root->right;
                rightscan->left=root->left;
                delete root;
                return rc;
           }
        }
          else{
            if(root->val<key){
                root->right=deleteNode(root->right,key);
            }
            else{
                root->left=deleteNode(root->left,key);
            }
          }
            return root;
    }
};