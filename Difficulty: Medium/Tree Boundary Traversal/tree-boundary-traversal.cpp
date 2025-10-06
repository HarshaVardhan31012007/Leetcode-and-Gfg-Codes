/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void leftB(Node *root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        if(root->right==NULL&&root->left==NULL){
            return;
        }
        ans.push_back(root->data);
        if(root->left!=NULL)
        leftB(root->left,ans);
        else{
            leftB(root->right,ans);
        }
    }
    void leafB(Node *root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        if(root->right==NULL&&root->left==NULL){
             ans.push_back(root->data);
            return;
        }
        leafB(root->left,ans);
        leafB(root->right,ans);
    }
    void rightB(Node *root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        if(root->right==NULL&&root->left==NULL){
            return;
        }
        if(root->right!=NULL)
        rightB(root->right,ans);
        else{
            rightB(root->left,ans);
        }
        ans.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        vector<int>ans;
        if(root==NULL)
        return ans;
        ans.push_back(root->data);
        leftB(root->left,ans);
        leafB(root->left,ans);
        leafB(root->right,ans);
        rightB(root->right,ans);
        return ans;
    }
};