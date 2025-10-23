/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
  public:
    bool flag;
    int solve(Node* root){
        if(!root) return 0;
        if(!root->left&!root->right) return root->data;
        int l=solve(root->left);
        int r=solve(root->right);
        if(flag&&l+r!=root->data)
        flag=0;
        return l+r+root->data;
    }
    bool isSumTree(Node* root) {
       flag=1;
       solve(root);
       return flag;
    }
};