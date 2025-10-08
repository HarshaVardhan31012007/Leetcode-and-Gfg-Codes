/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // void createPmap(TreeNode* root,map<TreeNode*,TreeNode*>&parent){
    //     if(root->left){
    //         parent[root->left]=root;
    //         createPmap(root->left,parent);
    //     }
    //     if(root->right){
    //         parent[root->right]=root;
    //         createPmap(root->right,parent);
    //     }
    // }
    // vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    //     unordered_map<TreeNode*,TreeNode*>parent;
    //     createPmap(root,parent);
    //     queue<pair<TreeNode*,int>>q;
    //     unordered_map<TreeNode*,bool>visited;
    //     q.push({target,0});
    //     visited[target]=1;
    //     vector<int>ans;
    //     while(!q.empty()&&k>0){
    //         int size=q.size();
    //         for(int i=0;i<size;i++){
    //         auto front=q.front().first;
    //         int dist=q.front().second;
    //         q.pop();
    //         if(front->left&&!visited[front->left]){
    //             visited[front->left]=true;
    //             q.push({front->left,dist+1});
    //         }
    //         if(front->right&&!visited[front->right]){
    //             visited[front->right]=true;
    //             q.push({front->right,dist+1});
    //         }
    //         if(parent[front]&&!visited[parent[front]]){
    //             visited[parent[front]]=true;
    //             q.push({parent[front],dist+1});
    //         }
    //         }
    //         k--;
    //     }
    //        while(!q.empty()){
    //             ans.push_back(q.front().first->val);
    //             q.pop();
    //        }
    //        return ans;
    // }


    //  void createPmap(TreeNode* root,map<TreeNode*,TreeNode*>&parent){
    //     if(root->left){
    //         parent[root->left]=root;
    //         createPmap(root->left,parent);
    //     }
    //     if(root->right){
    //         parent[root->right]=root;
    //         createPmap(root->right,parent);
    //     }
    // }
    // vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    //     unordered_map<TreeNode*,TreeNode*>parent;
    //     createPmap(root,parent);
    //     queue<TreeNode*>q;
    //     unordered_map<TreeNode*,bool>visited;
    //     q.push(target);
    //     visited[target]=1;
    //     vector<int>ans;
    //     while(!q.empty()&&k>0){
    //         int size=q.size();
    //         for(int i=0;i<size;i++){
    //         auto front=q.front();
    //         q.pop();
    //         if(front->left&&!visited[front->left]){
    //             visited[front->left]=true;
    //             q.push(front->left);
    //         }
    //         if(front->right&&!visited[front->right]){
    //             visited[front->right]=true;
    //             q.push(front->right);
    //         }
    //         if(parent[front]&&!visited[parent[front]]){
    //             visited[parent[front]]=true;
    //             q.push(parent[front]);
    //         }
    //         }
    //         k--;
    //     }
    //        while(!q.empty()){
    //             ans.push_back(q.front()->val);
    //             q.pop();
    //        }
    //        return ans;
    // }




//IT is a graph question which includes dfs and bfs
     void createPmap(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent){
        if(root->left){
            parent[root->left]=root;
            createPmap(root->left,parent);
        }
        if(root->right){
            parent[root->right]=root;
            createPmap(root->right,parent);
        }
    }
    void dfs(TreeNode* curr,unordered_map<TreeNode*,TreeNode*>&parent,unordered_map<TreeNode*,bool>&visited,int k,vector<int>&ans){
        if(k==0){
            ans.push_back(curr->val);
            return;
        }
            visited[curr]=1;
            if(curr->left&&!visited[curr->left]){
                dfs(curr->left,parent,visited,k-1,ans);
            }
            if(curr->right&&!visited[curr->right]){
                dfs(curr->right,parent,visited,k-1,ans);
            }
            if(parent[curr]&&!visited[parent[curr]]){
                dfs(parent[curr],parent,visited,k-1,ans);
            }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        createPmap(root,parent);
        unordered_map<TreeNode*,bool>visited;
        vector<int>ans;
        dfs(target,parent,visited,k,ans);
        return ans;
    }




    // void preorder(TreeNode* root,unordered_map<int,list<int>>&adjList){
    //     if(!root) return;
    //     preorder(root->left,adjList);
    //     preorder(root->right,adjList);
    //     if(root->left){
    //         adjList[root->val].push_back(root->left->val);
    //         adjList[root->left->val].push_back(root->val);
    //     }
    //     if(root->right){
    //         adjList[root->val].push_back(root->right->val);
    //         adjList[root->right->val].push_back(root->val);
    //     }
    // }
    // vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //graph
    //    unordered_map<int,list<int>>adjList;
    //    preorder(root,adjList);
    //    vector<int>ans;
    //    //bfs
    //    queue<int>q;
    //    unordered_map<int,bool>visited;
    //    q.push(target->val);
    //    visited[target->val]=true;
    //    while(!q.empty()&&k>0){
    //         int size=q.size();
    //         for(int i=0;i<size;i++){
    //             auto front=q.front();
    //             q.pop();
    //             for(auto &adj:adjList[front]){
    //                 if(!visited[adj]){
    //                     visited[adj]=true;
    //                     q.push(adj);
    //                 }
    //             }
    //         }
    //         k--;
    //    }
    //    while(!q.empty()){
    //       ans.push_back(q.front());
    //       q.pop();
    //    }
    //    return ans;
    // }





    //  void preorder(TreeNode* root,unordered_map<int,list<int>>&adjList){
    //     if(!root) return;
    //     preorder(root->left,adjList);
    //     preorder(root->right,adjList);
    //     if(root->left){
    //         adjList[root->val].push_back(root->left->val);
    //         adjList[root->left->val].push_back(root->val);
    //     }
    //     if(root->right){
    //         adjList[root->val].push_back(root->right->val);
    //         adjList[root->right->val].push_back(root->val);
    //     }
    // }
    // void dfs(int s,unordered_map<int,list<int>>&adjList,unordered_map<int,bool>&visited,int k,vector<int>&ans){
    //     if(k==0){
    //         ans.push_back(s);
    //         return;
    //     }
    //     visited[s]=1;
    //     for(auto &adj:adjList[s]){
    //         if(!visited[adj]){
    //             dfs(adj,adjList,visited,k-1,ans);
    //         }
    //     }
    // }
    // vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    //    unordered_map<int,list<int>>adjList;
    //    preorder(root,adjList);
    //    vector<int>ans;
    //    unordered_map<int,bool>visited;
    //    dfs(target->val,adjList,visited,k,ans);
    //    return ans;
    // }
};