// User function Template for C++
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
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        sort(edges.begin(),edges.end(),[&](vector<int>&a,vector<int>&b){
             if(a[2]!=b[2]) return a[2]<b[2];
             else if(a[0]!=b[0]) return a[0]<b[0];
             else if(a[1]!=b[1]) return a[1]<b[1];
        });
        DSU dsu(V);
        int sum=0;
        for(auto &each:edges){
            int u=each[0];
            int v=each[1];
            int w=each[2];
            if(dsu.find(u)!=dsu.find(v)){
                sum+=w;
                dsu.Union(u,v);
            }
        }
        return sum;
    }
};