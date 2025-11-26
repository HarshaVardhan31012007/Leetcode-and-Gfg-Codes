// User function Template for C++

/*struct Node {
    int data;
    Node *left, *right;
};*/

class Solution {
  public:
    void build(Node* root,vector<int>&inc){
        if(!root) return;
        build(root->left,inc);
        inc.push_back(root->data);
        build(root->right,inc);
    }
    void change(Node* root,vector<int>&inc,int &i){
         if(!root) return;
         change(root->left,inc,i);
         change(root->right,inc,i);
         root->data=inc[i++];
    }
    void convertToMaxHeapUtil(Node* root) {
        vector<int>inc;
        build(root,inc);
        int i=0;
        change(root,inc,i);
    }
};
