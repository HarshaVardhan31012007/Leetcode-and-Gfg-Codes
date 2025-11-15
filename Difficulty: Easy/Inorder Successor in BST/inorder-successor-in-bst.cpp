/*The structure of Node

struct Node {
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
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    int inOrderSuccessor(Node *root, Node *x) {
        Node* ans=0;
        while(root){
            if(root->data<=x->data){
                root=root->right;
            }
            else{
                ans=root;
                root=root->left;
            }
        }
        return ans==NULL?-1:ans->data;
    }
};