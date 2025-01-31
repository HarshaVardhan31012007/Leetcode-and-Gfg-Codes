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
//     int getHeight(TreeNode *root){
//         if(root==NULL){
//             return NULL;
//         }
//         int lans=getHeight(root->left);
//         int rans=getHeight(root->right);
//         return max(lans,rans)+1;
//   }


//method 2
int D=0;
int height(TreeNode *root){
    if(!root)return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    D=max(D,lh+rh);
    return max(lh,rh)+1;
}
    int diameterOfBinaryTree(TreeNode* root) {
        // if(root==NULL){
        //     return 0;
        // }
        // int option1=diameterOfBinaryTree(root->left);
        // int option2=diameterOfBinaryTree(root->right);
        // int option3=getHeight(root->left)+getHeight(root->right);
        // int ans=max(option1,max(option2,option3));
        // return ans;


        //method 2
        height(root);
        return D;
    }
};