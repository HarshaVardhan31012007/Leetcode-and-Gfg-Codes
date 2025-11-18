/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    class Info{
        public:
        int mini;
        int maxi;
        bool isBST;
        int size;
    };
    Info solve(Node* root,int &ans){
        if(!root) return {INT_MAX,INT_MIN,true,0};
        Info l=solve(root->left,ans);
        Info r=solve(root->right,ans);
        if(root->data>l.maxi&&root->data<r.mini&&l.isBST&&r.isBST){
            Info curr;
            curr.mini=min(l.mini,root->data);
            curr.maxi=max(root->data,r.maxi);
            curr.size=l.size+r.size+1;
            ans=max(ans,curr.size);
            curr.isBST=true;
            return curr;
        }
        return {INT_MIN,INT_MAX,false,1};
    }
    int largestBst(Node *root) {
         int ans=0;
         solve(root,ans);
         return ans;
    }
};