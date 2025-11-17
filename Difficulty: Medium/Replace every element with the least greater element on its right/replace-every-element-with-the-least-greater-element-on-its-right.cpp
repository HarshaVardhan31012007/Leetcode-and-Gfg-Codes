//Back-end complete function Template for C++

class Solution {
  public:
    class Node{
        public:
        int data;
        Node* left;
        Node* right;
        Node(int val):data(val),left(0),right(0){}
    };
    Node* build(Node* root,int val,int &succ){
        if(!root) return new Node(val);
        if(val>=root->data){
            root->right=build(root->right,val,succ);
        }
        else{
            succ=root->data;
            root->left=build(root->left,val,succ);
        }
        return root;
    }
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int>ans(n);
        Node* root=NULL;
        for(int i=n-1;i>=0;i--){
            int succ=-1;
            root=build(root,arr[i],succ);
            ans[i]=succ;
        }
        return ans;
    }
};