/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
         map<int,Node*>mpp;
        queue<pair<int,Node*>>q;
        q.push({0,root});
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            mpp[front.first]=front.second;
            if(front.second->left)
            q.push({front.first-1,front.second->left});
            if(front.second->right)
            q.push({front.first+1,front.second->right});
        }
        vector<int>ans;
        for(auto it=mpp.begin();it!=mpp.end();it++){
            ans.push_back(it->second->data);
        }
        return ans;
    }
};