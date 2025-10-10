/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //method 1
    // struct s{
    //     vector<int>data;
    //     int x1;
    //     int y;
    // };
    // int find(vector<s>&v,int i,int j){
    //     for(int k=0;k<v.size();k++){
    //         if(v[k].x1==i&&v[k].y==j){
    //             return k;
    //         }
    //     }
    //     return -1;
    // }
    // void solve(TreeNode *root,vector<s>&v,int l,int x,int &minx,int &maxx,int &lmax){
    //     if(root==NULL){
    //         return;
    //     }
    //     lmax=max(l,lmax);
    //     minx=min(minx,x);
    //     maxx=max(maxx,x);
    //     int index=find(v,x,l);
    //     if(index==-1){
    //     vector<int>p;
    //     p.push_back(root->val);
    //     v.push_back({p,x,l});
    //     }
    //     else{
    //        v[index].data.push_back(root->val);
    //        sort(v[index].data.begin(),v[index].data.end());
    //     }
    //     solve(root->left,v,l+1,x-1,minx,maxx,lmax);
    //     solve(root->right,v,l+1,x+1,minx,maxx,lmax);
    // }
     vector<vector<int>> verticalTraversal(TreeNode* root) {
    //     vector<s>v;
    //     vector<vector<int>>ans;
    //     int l=0;
    //     int x=0;
    //     int minx=INT_MAX;
    //     int maxx=INT_MIN;
    //     int lmax=INT_MIN;
    //     solve(root,v,l,x,minx,maxx,lmax);
    //     for(int i=minx;i<=maxx;i++){
    //         vector<int>temp;
    //         for(int j=0;j<=lmax;j++){
    //             int index=find(v,i,j);
    //             if(index!=-1){
    //             for(int k=0;k<v[index].data.size();k++){
    //             temp.push_back(v[index].data[k]);
    //             }
    //             }
    //         }
    //         if(!temp.empty())
    //         ans.push_back(temp);
    //     }
    //     return ans;
    // }

    //method 2
    // void solve(TreeNode *root,map<int,map<int,vector<int>>>&mpp,int r,int c){
    //     if(root==NULL){
    //         return;
    //     }
    //     mpp[c][r].push_back(root->val);
    //     // if(mpp[c][r].size()>1){
    //     //     sort(mpp[c][r].begin(),mpp[c][r].end());
    //     // }
    //     solve(root->left,mpp,r+1,c-1);
    //     solve(root->right,mpp,r+1,c+1);
    // }
    // vector<vector<int>> verticalTraversal(TreeNode* root) {
    //   vector<vector<int>>ans;
    //   map<int,map<int,vector<int>>>mpp;
    //   if(root==NULL){
    //     return ans;
    //   }
    //   int r=0;
    //   int c=0;
    //   solve(root,mpp,r,c);
    //   for(auto i:mpp){
    //     vector<int>temp;
    //     for(auto j:i.second){
    //     //    for(auto k:j.second){
    //     //         temp.push_back(k);
    //     //    }
    //     sort(j.second.begin(),j.second.end());
    //     temp.insert(temp.end(),j.second.begin(),j.second.end());
    //     }
    //     ans.push_back(temp);
    //   }
    //   return ans;



    //method 3
    //    vector<vector<int>>ans;
    //   map<int,map<int,vector<int>>>mpp;
    //   queue<pair<TreeNode*,pair<int,int>>>q;
    //   if(root==NULL){
    //     return ans;
    //   }
    //   q.push({root,make_pair(0,0)});
    //   while(!q.empty()){
    //       auto front=q.front();
    //       q.pop();
    //       mpp[front.second.second][front.second.first].push_back(front.first->val);
    //       if(front.first->left!=NULL){
    //         q.push({front.first->left,{front.second.first+1,front.second.second-1}});
    //       }
    //       if(front.first->right!=NULL){
    //         q.push({front.first->right,{front.second.first+1,front.second.second+1}});
    //       }
    //   }
    //      for(auto i:mpp){
    //     vector<int>temp;
    //     for(auto j:i.second){
    //     //    for(auto k:j.second){
    //     //         temp.push_back(k);
    //     //    }
    //     sort(j.second.begin(),j.second.end());
    //     temp.insert(temp.end(),j.second.begin(),j.second.end());
    //     }
    //     ans.push_back(temp);
    //   }
    //   return ans;

    //method 4
         queue<pair<TreeNode*,pair<int,int>>>q;
         map<int,map<int,multiset<int>>>mpp;// set dont allow duplicate //here node values may be same
         vector<vector<int>>ans;
         if(!root) return ans;
         q.push({root,{0,0}});
         while(!q.empty()){
              auto front=q.front().first;
              int x=q.front().second.first;
              int y=q.front().second.second;
              q.pop();
              mpp[x][y].insert(front->val);
              if(front->left)
              q.push({front->left,{x-1,y+1}});
              if(front->right)
              q.push({front->right,{x+1,y+1}});
         }
         for(auto &i:mpp){
            vector<int>temp;
            for(auto &j:i.second){
                temp.insert(temp.end(),j.second.begin(),j.second.end());
            }
            ans.push_back(temp);
         }
         return ans;
    }
};