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
    int largestIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        DSU dsu(m*n);
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                for(int k=0;k<4;k++){
                    int x=i+dx[k];
                    int y=j+dy[k];
                    if(x<0||y<0||x>=m||y>=n||grid[x][y]==0) continue;
                    int u=i*n+j;
                    int v=x*n+y;
                    dsu.Union(u,v);
                }
            }
        }
        unordered_map<int,int>comp;
        int maxi=INT_MIN;
        for(int i=0;i<m*n;i++){
            if(grid[i/n][i%n]==0) continue;
            int par=dsu.find(i);
            comp[par]++;
            maxi=max(maxi,comp[par]);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int sum=0;
                    unordered_set<int>st;
                    for(int k=0;k<4;k++){
                        int x=i+dx[k];
                        int y=j+dy[k];
                        if(x<0||y<0||x>=m||y>=n||grid[x][y]==0) continue;
                        int v=x*n+y;
                        st.insert(dsu.find(v));
                    }
                    for(auto &each:st)
                    sum+=comp[each];
                    sum++;
                    maxi=max(maxi,sum);
                }
            }
        }
        return maxi;
    }
};