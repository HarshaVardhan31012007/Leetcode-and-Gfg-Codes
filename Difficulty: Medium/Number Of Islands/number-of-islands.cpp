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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DSU dsu(n*m);
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        vector<vector<int>>grid(n,vector<int>(m,0));
        vector<int>ans;
        for(auto &op:operators){
            int i=op[0];int j=op[1];
            grid[i][j]=1;
            for(int k=0;k<4;k++){
                 int x=i+dx[k];
                 int y=j+dy[k];
                 if(x<0||y<0||x>=n||y>=m||grid[x][y]==0) continue;
                 int u=i*m+j;
                 int v=x*m+y;
                 dsu.Union(u,v);
            }
            int count=0;
            for(int i=0;i<m*n;i++){
                if(dsu.parent[i]==i&&grid[i/m][i%m]==1)
                count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};
