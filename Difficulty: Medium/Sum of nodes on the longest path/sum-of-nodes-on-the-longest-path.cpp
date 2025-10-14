/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    void solve(Node* root,int sum,int &ans,int level,int &maxlevel){
        if(!root) return;
        if(!root->left&&!root->right){
            sum+=root->data;
            if(maxlevel==level)
            ans=max(ans,sum);
            else if(level>maxlevel){
                maxlevel=level;
                ans=sum;
            }
            return;
        }
        solve(root->left,sum+root->data,ans,level+1,maxlevel);
        solve(root->right,sum+root->data,ans,level+1,maxlevel);
    }
    int sumOfLongRootToLeafPath(Node *root) {
        int ans=INT_MIN;int maxlevel=INT_MIN;
        solve(root,0,ans,0,maxlevel);
        return ans;
    }
};