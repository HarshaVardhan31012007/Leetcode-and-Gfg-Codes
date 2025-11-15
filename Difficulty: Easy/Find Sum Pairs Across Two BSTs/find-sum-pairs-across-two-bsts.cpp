/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // void build(Node* root,vector<int>&v){
    //     if(!root) return;
    //     build(root->left,v);
    //     v.push_back(root->data);
    //     build(root->right,v);
    // }
    // int countPairs(Node* root1, Node* root2, int x) {
    //     vector<int>a;
    //     vector<int>b;
    //     build(root1,a);
    //     build(root2,b);
    //     int i=0;
    //     int j=b.size()-1;
    //     int count=0;
    //     while(i<a.size()&&j>=0){
    //         if(a[i]+b[j]==x){
    //             count++;
    //             i++;j--;
    //         }
    //         else if(a[i]+b[j]<x){
    //             i++;
    //         }
    //         else
    //         j--;
    //     }
    //     return count;
    // }
    
    
    
    // void build(Node* root,vector<int>&v){
    //     if(!root) return;
    //     build(root->left,v);
    //     v.push_back(root->data);
    //     build(root->right,v);
    // }
    // void build1(Node* root,vector<int>&v){
    //     if(!root) return;
    //     build1(root->right,v);
    //     v.push_back(root->data);
    //     build1(root->left,v);
    // }
    // int countPairs(Node* root1, Node* root2, int x) {
    //     vector<int>a;
    //     vector<int>b;
    //     build(root1,a);
    //     build1(root2,b);
    //     int i=0;
    //     int j=0;
    //     int count=0;
    //     while(i<a.size()&&j<b.size()){
    //         if(a[i]+b[j]==x){
    //             count++;
    //             i++;j++;
    //         }
    //         else if(a[i]+b[j]<x){
    //             i++;
    //         }
    //         else
    //         j++;
    //     }
    //     return count;
    // }
    
    
    void pushLeftNodes(Node* root,stack<Node*>&s){
        while(root){
            s.push(root);
            root=root->left;
        }
    }
    void pushRightNodes(Node* root,stack<Node*>&s){
        while(root){
            s.push(root);
            root=root->right;
        }
    }
    int countPairs(Node* root1, Node* root2, int x) {
         stack<Node*>st;
         stack<Node*>revst;
         pushLeftNodes(root1,st);
         pushRightNodes(root2,revst);
         int count=0;
         while(!st.empty()&&!revst.empty()){
             Node* a=st.top();
             Node* b=revst.top();
             if(a->data+b->data==x){
                 st.pop();
                 revst.pop();
                 count++;
                 pushLeftNodes(a->right,st);
                 pushRightNodes(b->left,revst);
             }
             else if(a->data+b->data<x){
                 st.pop();
                 pushLeftNodes(a->right,st);
             }
             else{
                 revst.pop();
                 pushRightNodes(b->left,revst);
             }
         }
         return count;
    }
    
};