class Solution {
public:
    // void dfs(int src,int V,vector<vector<int>>&isConnected,vector<int>&visited){
    //       visited[src]=1;
    //       for(int i=0;i<V;i++){
    //          if(!visited[i]&&isConnected[src][i]){
    //             dfs(i,V,isConnected,visited);
    //          }
    //       }
    // }
    // int findCircleNum(vector<vector<int>>& isConnected) {
    //     int noOfProvinces=0;
    //     int V=isConnected.size();
    //     vector<int>visited(V,0);
    //     for(int i=0;i<V;i++){
    //         if(!visited[i]){
    //             dfs(i,V,isConnected,visited);
    //             noOfProvinces++;
    //         }
    //     }
    //     return noOfProvinces;
    // }


    class DSU{
        public:
        vector<int>parent,rank;
        
        DSU(int n){
            parent.resize(n);
            rank.resize(n,0);
            for(int i=0;i<n;i++)
            parent[i]=i;
        }
        
        int find(int node){
            if(parent[node]==node) return node;
            return parent[node]=find(parent[node]);
        }
        
        void Union(int node1,int node2){
            int u=find(node1);
            int v=find(node2);
            if(u==v) return;
            if(rank[u]<rank[v]){
                parent[u]=v;
            }
            else if(rank[u]>rank[v]){
                parent[v]=u;
            }
            else{
                parent[v]=u;
                rank[u]++;
            }
        }
    };
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();          
        DSU dsu(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]){
                    dsu.Union(i,j);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(dsu.parent[i]==i) count++;
        }
        return count;
    }
};