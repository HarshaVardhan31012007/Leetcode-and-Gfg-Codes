/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node *flatten(Node *root) {
        if(!root) return root;
        flatten(root->next);
        if(root->bottom&&root->next){
                Node* it1=root->next;
                Node* it2=root->bottom;
                Node* it=root;
                while(it1&&it2){
                    if(it1->data<=it2->data){
                        it->bottom=it1;
                        it=it->bottom;
                        it1=it1->bottom;
                    } else{
                        it->bottom=it2;
                        it=it->bottom;
                        it2=it2->bottom;
                    }
                }
                if(it1){
                    it->bottom=it1;
                }
                if(it2){
                    it->bottom=it2;
                }
        }
        else if(root->next){
            root->bottom=root->next;
            root->next=NULL;
        }
        //cout<<root->data<<endl;
        return root;
    }
};