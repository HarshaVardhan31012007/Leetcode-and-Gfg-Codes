/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:

    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int solve(Node* root){
        if(!root) return 0;
        int l=solve(root->left);
        int r=solve(root->right);
        int curr=root->data;
        root->data=l+r;
        return curr+root->data;
    }
    void toSumTree(Node *node) {
       solve(node);
    }
};