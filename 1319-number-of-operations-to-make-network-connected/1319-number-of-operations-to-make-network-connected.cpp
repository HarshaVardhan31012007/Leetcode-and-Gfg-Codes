class Solution {
public:
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges=connections.size();
        if(edges<n-1) return -1;
        DSU dsu(n);
        for(int i=0;i<edges;i++){
            int u=connections[i][0];
            int v=connections[i][1];
            dsu.Union(u,v);
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(dsu.parent[i]==i) count++;
        }
        return count-1;
    }
};