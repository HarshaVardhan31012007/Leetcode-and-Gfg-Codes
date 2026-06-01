class Solution {
public:
    long long dfs(int i,vector<int>adj[],vector<int>&visited){
        visited[i]=1;
        long long ans=0;
        for(auto &node:adj[i]){
            if(!visited[node]){
                ans+=dfs(node,adj,visited);
            }
        }
        return ans+1;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto &edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int>visited(n,false);
        long long ans=0;
        for(int i=0;i<n;i++){
           if(!visited[i]){
              long long count=dfs(i,adj,visited);
              ans+=count*(n-count);
           }
        }
        return ans/2;
    }
};