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
    void build(Node* root,vector<int>&v){
        if(!root) return;
        build(root->left,v);
        v.push_back(root->data);
        build(root->right,v);
    }
    int countPairs(Node* root1, Node* root2, int x) {
        vector<int>a;
        vector<int>b;
        build(root1,a);
        build(root2,b);
        int i=0;
        int j=b.size()-1;
        int count=0;
        while(i<a.size()&&j>=0){
            if(a[i]+b[j]==x){
                count++;
                i++;j--;
            }
            else if(a[i]+b[j]<x){
                i++;
            }
            else
            j--;
        }
        return count;
    }
};