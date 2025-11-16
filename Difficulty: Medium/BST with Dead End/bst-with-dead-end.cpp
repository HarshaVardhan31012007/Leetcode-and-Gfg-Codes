/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
    bool isDeadEnd(Node *root,int mini=0,int maxi=INT_MAX) {
       if(!root) return false;
       if(!root->left&&!root->right&&root->data==mini+1&&root->data==maxi-1){
           return true;
       }
       return isDeadEnd(root->left,mini,root->data)||isDeadEnd(root->right,root->data,maxi);
    }
};