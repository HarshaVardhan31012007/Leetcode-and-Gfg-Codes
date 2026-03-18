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
    int removeStones(vector<vector<int>>& points) {
        unordered_map<int,int>xMap;
        unordered_map<int,int>yMap;
        DSU dsu(points.size());
        for(int i=0;i<points.size();i++){
           if(!xMap.count(points[i][0])) xMap[points[i][0]]=i;
           else dsu.Union(i,xMap[points[i][0]]);
           if(!yMap.count(points[i][1])) yMap[points[i][1]]=i;
           else dsu.Union(i,yMap[points[i][1]]);
        }
        vector<int>compSize(points.size(),0);
        for(int i=0;i<points.size();i++){
            int u=dsu.find(i);
            compSize[u]++;
        }
        int sum=0;
        for(auto &each:compSize){
            if(each>0)
            sum+=each-1;
        }
        return sum;
    }
};