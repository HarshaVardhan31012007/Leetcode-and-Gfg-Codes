/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int solve(Node* root,int &maxi,bool &flag,int i){
        if(!root) return 0;
        if(root->left&&root->data<root->left->data&&flag)
        flag=false;
        if(root->right&&root->data<root->right->data&&flag)
        flag=false;
        maxi=max(maxi,i);
        int l=solve(root->left,maxi,flag,2*i);
        int r=solve(root->right,maxi,flag,2*i+1);
        return l+r+1;
    }
    bool isHeap(Node* tree) {
        bool flag=true;
        int maxi=INT_MIN;
        int i=1;
        int count=solve(tree,maxi,flag,i);
        return flag&&(count==maxi);
    }
};