/*
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left, *right;
};
*/
// your task is to complete this function
class Solution {
  public:
    void solve(Node* root,int &k,int k1,int node,int &ans){
        if(!root) return;
        if(root->data==node) {
            k--;
            return;
        }
        if(k1==k)
        solve(root->left,k,k1,node,ans);
        if(k1==k)
        solve(root->right,k,k1,node,ans);
        if(k==0)
        ans=root->data;
        if(k1!=k)
        k--;
    }
    int kthAncestor(Node *root, int k, int node) {
        int ans=-1;
        solve(root,k,k,node,ans);
        return ans;
    }
};
