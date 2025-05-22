class Solution {
  public:
//   class node{
//      public:
//      pair<int,char>p;
//      node *left;
//      node *right;
//      node(int a,char b){
//          this->p={a,b};
//          this->left=NULL;
//          this->right=NULL;
//      }
//   };
//   class comp{
//       public:
//       bool operator()(node *&a,node *&b){
//           return a->p.first>b->p.first;
//       }
//   };
//     void solve(node *root,vector<string>&ans,string temp){
//         if(!root->left&&!root->right){
//             ans.push_back(temp);
//             return;
//         }
//         solve(root->left,ans,temp+'0');
//         solve(root->right,ans,temp+'1');
//     }
//     vector<string> huffmanCodes(string S, vector<int> f, int N) {
//         priority_queue<node*,vector<node*>,comp>pq;
//         for(int i=0;i<f.size();i++){
//             pq.push(new node(f[i],S[i]));
//         }
//         node *root=NULL;
//         while(!pq.empty()){
//             node *a=pq.top();
//             pq.pop();
//             node *b=NULL;
//             if(!pq.empty()){
//             b=pq.top();
//             pq.pop();
//             }
//             if(b!=NULL){
//             root=new node(a->p.first+b->p.first,'\0');
//             root->left=a;
//             root->right=b;
//             pq.push(root);
//             }
//         }
//         vector<string>ans;
//         string temp="";
//         solve(root,ans,temp);
//         return ans;
//     }


class node{
     public:
     int data;
     node *left;
     node *right;
     node(int a){
         this->data=a;
         this->left=NULL;
         this->right=NULL;
     }
  };
  class comp{
      public:
      bool operator()(node *&a,node *&b){
          return a->data>b->data;
      }
  };
    void solve(node *root,vector<string>&ans,string temp){
        if(!root->left&&!root->right){
            ans.push_back(temp);
            return;
        }
        solve(root->left,ans,temp+'0');
        solve(root->right,ans,temp+'1');
    }
    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        priority_queue<node*,vector<node*>,comp>pq;
        for(int i=0;i<f.size();i++){
            pq.push(new node(f[i]));
        }
        while(pq.size()>1){
           node *a=pq.top();
           pq.pop();
           node *b=pq.top();
           pq.pop();
           node *root=new node(a->data+b->data);
           root->left=a;
           root->right=b;
           pq.push(root);
        }
        node *root=pq.top();
        vector<string>ans;
        string temp="";
        solve(root,ans,temp);
        return ans;
    }
};