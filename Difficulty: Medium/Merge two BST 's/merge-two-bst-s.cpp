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
    void pushLeftNodes(Node* root,stack<Node*>&s){
        while(root){
            s.push(root);
            root=root->left;
        }
    }
    vector<int> merge(Node *root1, Node *root2) {
        vector<int>ans;
        stack<Node*>st;
        stack<Node*>s;
        pushLeftNodes(root1,s);
        pushLeftNodes(root2,st);
        while(!s.empty()&&!st.empty()){
            Node* a=s.top();
            Node* b=st.top();
            if(a->data>b->data){
                st.pop();
                ans.push_back(b->data);
                pushLeftNodes(b->right,st);
            }
            else{
                s.pop();
                ans.push_back(a->data);
                pushLeftNodes(a->right,s);
            }
        }
        while(!s.empty()){
            Node* a=s.top();
            s.pop();
            ans.push_back(a->data);
            pushLeftNodes(a->right,s);
        }
        while(!st.empty()){
            Node* b=st.top();
            st.pop();
            ans.push_back(b->data);
            pushLeftNodes(b->right,st);
        }
        return ans;
    }
};