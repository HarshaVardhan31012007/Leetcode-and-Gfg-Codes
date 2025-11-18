/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    // void solve(Node* a,Node* b,int l,int &maxl){
    //     if(!a&&!b) return;
    //     if(l>maxl){
    //         maxl=l;
    //         solve(b->left,b->right,l+1,maxl);
    //     }
    //     a->next=b;
    //     solve(a->left,a->right,l+1,maxl);
    //     solve(a->right,b->left,l+1,maxl);
    // }
    // Node* connect(Node* root) {
    //     if(!root||!root->left&&!root->right) return root;
    //     int l=1;
    //     int maxl=0;
    //     solve(root->left,root->right,l,maxl);
    //     return root;
    // }



    Node* connect(Node* root) {
         if(!root) return root;
         Node* level=root;
         while(level->left){
            Node* curr=level;
            while(curr){
                curr->left->next=curr->right;
                if(curr->next)
                curr->right->next=curr->next->left;
                curr=curr->next;
            }
            level=level->left;
         }
         return root;
    }
};