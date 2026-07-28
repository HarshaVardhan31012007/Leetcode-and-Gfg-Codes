// class Solution {
// public:
//     vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
//         vector<set<int>>ans(n);
//         vector<int>inorder(n,0);
//         vector<vector<int>>adj(n);
//         for(auto &each:edges){
//             adj[each[0]].push_back(each[1]);
//             inorder[each[1]]++;
//         }
//         queue<int>q;
//         for(int i=0;i<n;i++){
//             if(inorder[i]==0){
//                 q.push(i);
//             }
//         }
//         while(!q.empty()){
//             int node=q.front();
//             q.pop();
//             for(auto &adjNode:adj[node]){
//                 ans[adjNode].insert(ans[node].begin(),ans[node].end());
//                 ans[adjNode].insert(node);
//                 inorder[adjNode]--;
//                 if(inorder[adjNode]==0)
//                 q.push(adjNode);
//             }
//         }
//         vector<vector<int>>temp;
//         for(auto &each:ans){
//             temp.push_back(vector<int>(each.begin(),each.end()));
//         }
//         return temp;
//     }
// };



// class Solution {
// public:
//     vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
//         vector<set<int>>ans(n);
//         vector<int>inorder(n,0);
//         vector<vector<int>>adj(n);
//         for(auto &each:edges){
//             adj[each[0]].push_back(each[1]);
//             inorder[each[1]]++;
//         }
//         queue<int>q;
//         for(int i=0;i<n;i++){
//             if(inorder[i]==0){
//                 q.push(i);
//             }
//         }
//         vector<int>topo;
//         while(!q.empty()){
//             int node=q.front();
//             q.pop();
//             topo.push_back(node);
//             for(auto &adjNode:adj[node]){
//                 inorder[adjNode]--;
//                 if(inorder[adjNode]==0)
//                 q.push(adjNode);
//             }
//         }
//         for(auto &node:topo){
//             for(auto &each:adj[node]){
//                 ans[each].insert(ans[node].begin(),ans[node].end());
//                 ans[each].insert(node);
//             }
//         }
//         vector<vector<int>>temp;
//         for(auto &each:ans){
//             temp.push_back(vector<int>(each.begin(),each.end()));
//         }
//         return temp;
//     }
// };



// class Solution {
// public:
//     vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
//         vector<unordered_set<int>>ans(n);
//         vector<int>inorder(n,0);
//         vector<vector<int>>adj(n);
//         for(auto &each:edges){
//             adj[each[0]].push_back(each[1]);
//             inorder[each[1]]++;
//         }
//         queue<int>q;
//         for(int i=0;i<n;i++){
//             if(inorder[i]==0){
//                 q.push(i);
//             }
//         }
//         vector<int>topo;
//         while(!q.empty()){
//             int node=q.front();
//             q.pop();
//             topo.push_back(node);
//             for(auto &adjNode:adj[node]){
//                 inorder[adjNode]--;
//                 if(inorder[adjNode]==0)
//                 q.push(adjNode);
//             }
//         }
//         for(auto &node:topo){
//             for(auto &each:adj[node]){
//                 ans[each].insert(ans[node].begin(),ans[node].end());
//                 ans[each].insert(node);
//             }
//         }
//         vector<vector<int>>temp;
//         for(auto &each:ans){
//             temp.push_back(vector<int>(each.begin(),each.end()));
//             sort(temp.back().begin(),temp.back().end());
//         }
//         return temp;
//     }
// };



class Solution {
public:
    void dfs(int ancestor,vector<vector<int>>&adj,int node,vector<vector<int>>&ans,vector<int>&visited){
        visited[node]=true;
        for(auto &each:adj[node]){
            if(!visited[each]){
               dfs(ancestor,adj,each,ans,visited);
               ans[each].push_back(ancestor);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto &each:edges){
            adj[each[0]].push_back(each[1]);
        }
        vector<vector<int>>ans(n);
        for(int i=0;i<n;i++){
            vector<int>visited(n,false);
            dfs(i,adj,i,ans,visited);
        }
        return ans;
    }
};