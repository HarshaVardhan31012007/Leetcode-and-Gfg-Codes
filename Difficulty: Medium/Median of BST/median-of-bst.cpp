/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int count(Node* root){
        if(!root) return 0;
        return 1+count(root->left)+count(root->right);
    }
    void solve(Node* root,int idx,int &i,int &ans){
        if(!root) return;
        solve(root->left,idx,i,ans);
        i++;
        if(i==idx){
            ans=root->data;
            return;
        }
        solve(root->right,idx,i,ans);
    }
    int findMedian(Node* root) {
        int n=count(root);
        int ans=0;
        int idx=0;
        if(n&1) idx=(n+1)/2;
        else idx=n/2;
        int i=0;
        solve(root,idx,i,ans);
        return ans;
    }
};