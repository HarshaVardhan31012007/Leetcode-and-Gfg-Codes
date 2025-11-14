/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void solve(Node* root,vector<Node*>&ans,int key){
        if(!root) return;
        solve(root->left,ans,key);
        if(root->data<key)
        ans[0]=root;
        if(!ans[1]&&root->data>key)
        ans[1]=root;
        solve(root->right,ans,key);
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        vector<Node*>ans(2,NULL);
        solve(root,ans,key);
        return ans;
    }
};