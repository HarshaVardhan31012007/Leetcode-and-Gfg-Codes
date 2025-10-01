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
    int getMin(TreeNode* root){
        while(root->left!=NULL)
        root=root->left;
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key){
            if(!root->left&&!root->right){
                delete root;
                return NULL;
            }
            else if(root->left&&!root->right){
                TreeNode* leftChild=root->left;
                root->left=NULL;
                delete root;
                return leftChild;
            }
            else if(!root->left&&root->right){
                TreeNode* rightChild=root->right;
                root->right=NULL;
                delete root;
                return rightChild;
            }
            else{
                int minVal=getMin(root->right);
                root->val=minVal;
                root->right=deleteNode(root->right,minVal);
                return root;
            }
        }
        else if(root->val<key){
            root->right=deleteNode(root->right,key);
        }
        else
        root->left=deleteNode(root->left,key);
        return root;
    }
};