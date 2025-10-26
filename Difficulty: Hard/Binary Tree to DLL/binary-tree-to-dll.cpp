/* Structure for tree and linked list
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node()
        : data(0)
        , left(NULL)
        , right(NULL) {}

    Node(int x)
        : data(x)
        , left(NULL)
        , right(NULL) {}
};
 */

// This function should return head to the DLL
class Solution {
  public:
    void solve(Node* root,Node* &head,Node* &prev){
        if(!root) return;
        solve(root->left,head,prev);
        if(!prev){
            head=root;
            prev=root;
        }
        else{
            prev->right=root;
            root->left=prev;
            prev=root;
        }
        solve(root->right,head,prev);
    }
    Node* bToDLL(Node* root) {
       Node* head=NULL;
       Node* prev=NULL;
       solve(root,head,prev);
       return head;
    }
};