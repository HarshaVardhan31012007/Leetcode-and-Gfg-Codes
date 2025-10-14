/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    unordered_map<Node*,int>mpp;
    int getMaxSum(Node *root) {
       if(!root) return 0;
       if(mpp.find(root)!=mpp.end()) return mpp[root];
       int inc=root->data;
       if(root->left)
       inc+=getMaxSum(root->left->left)+getMaxSum(root->left->right);
       if(root->right)
       inc+=getMaxSum(root->right->left)+getMaxSum(root->right->right);
       int exc=getMaxSum(root->left)+getMaxSum(root->right);
       return mpp[root]=max(inc,exc);
    }
};