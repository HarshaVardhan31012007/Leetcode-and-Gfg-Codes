// class Solution {
// public:
//     bool possible(int node,int currColor,vector<vector<int>>&graph,vector<int>&color){
//         color[node]=currColor;
//         for(auto &adjNode:graph[node]){
//             if(color[adjNode]==color[node]) return false;
//             if(color[adjNode]==-1){
//                 if(!possible(adjNode,!currColor,graph,color)) return false;
//             }
//         }
//         return true;
//     }
//     bool isBipartite(vector<vector<int>>& graph) {
//         int n=graph.size();
//         vector<int>color(n,-1);
//         for(int i=0;i<n;i++){
//             if(color[i]==-1){
//                 if(!possible(i,0,graph,color)) return false;
//             }
//         }
//         return true;
//     }
// };



// class Solution {
// public:
//     bool possible(int node,int currColor,vector<vector<int>>&graph,vector<int>&color){
//         queue<int>q;
//         q.push(node);
//         color[node]=currColor;
//         while(!q.empty()){
//             int fNode=q.front();
//             q.pop();
//             for(auto &adjNode:graph[fNode]){
//                 if(color[adjNode]==color[fNode]) return false;
//                 if(color[adjNode]==-1){
//                     color[adjNode]=1-color[fNode];
//                     q.push(adjNode);
//                 }
//             }
//         }
//         return true;
//     }
//     bool isBipartite(vector<vector<int>>& graph) {
//         int n=graph.size();
//         vector<int>color(n,-1);
//         for(int i=0;i<n;i++){
//             if(color[i]==-1){
//                 if(!possible(i,0,graph,color)) return false;
//             }
//         }
//         return true;
//     }
// };



class Solution {
public:
    int find(int node,vector<int>&parent){
        if(node==parent[node]) return node;
        return parent[node]=find(parent[node],parent);
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>parent(n,0);
        for(int i=0;i<n;i++)
        parent[i]=i;
        for(int i=0;i<n;i++){
            if(graph[i].empty()) continue;
            int x=find(graph[i][0],parent);
            for(auto &adjNode:graph[i]){
               int u=i;
               int v=adjNode;
               u=find(u,parent);
               v=find(v,parent);
               if(u==v) return false;
               parent[v]=x;
            }
        }
        return true;
    }
};