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
    //     if(!a||!b) return;
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
         while(level->left||level->right||level->next){
            Node* curr=level;
            Node* prev=NULL;
            while(curr){
                if(prev!=NULL){
                   if(curr->left){
                   prev->next=curr->left;
                   prev=curr->left;
                   if(curr->right){
                    curr->left->next=curr->right;
                    prev=curr->right;
                   }
                   }
                   else if(curr->right){
                   prev->next=curr->right;
                   prev=curr->right;
                   }
                }
                else{
                    if(curr->left&&curr->right){
                        curr->left->next=curr->right;
                        prev=curr->right;
                    }
                    else if(curr->left){
                        prev=curr->left;
                    }
                    else if(curr->right)
                    prev=curr->right;
                }
                curr=curr->next;
            }
            if(level->left)
            level=level->left;
            else if(level->right)
            level=level->right;
            else if(level->next)
            level=level->next;
            else
            break;
         }
         return root;
    }
};