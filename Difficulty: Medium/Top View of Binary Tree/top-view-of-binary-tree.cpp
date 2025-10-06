/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    void solve(Node* root,int x,int level,map<int,pair<Node*,int>>&mpp){
        if(!root) return;
        if(mpp.find(x)!=mpp.end()){
            if(level<mpp[x].second)
            mpp[x]={root,level};
        }
        else{
            mpp[x]={root,level};
        }
        solve(root->left,x-1,level+1,mpp);
        solve(root->right,x+1,level+1,mpp);
    }
    vector<int> topView(Node *root) {
        map<int,pair<Node*,int>>mpp;
        solve(root,0,0,mpp);
        vector<int>ans;
        for(auto it=mpp.begin();it!=mpp.end();it++){
             ans.push_back(it->second.first->data);
        }
        return ans;
    }
};