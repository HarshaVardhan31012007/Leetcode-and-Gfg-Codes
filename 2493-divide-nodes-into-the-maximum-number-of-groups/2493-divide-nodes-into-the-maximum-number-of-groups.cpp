class Solution {
public:
    int bfs(int node,vector<vector<int>>&adj){
        queue<int>q;
        vector<int>visited(adj.size(),0);
        q.push(node);
        visited[node]=1;
        int level=0;
        while(!q.empty()){
            level++;
            int size=q.size();
            for(int i=0;i<size;i++){
                int front=q.front();
                q.pop();
                for(auto &adjNode:adj[front]){
                    if(!visited[adjNode]){
                        q.push(adjNode);
                        visited[adjNode]=(level+1);
                    }
                    else{
                        int grp1=visited[adjNode];
                        // if(abs(grp1-level)!=1) return INT_MIN;
                        if(grp1==level) return INT_MIN;
                    }
                }
            }
        }
        return level;
    }
    int find(int node,vector<int>&parent){
        if(node==parent[node]) return node;
        return parent[node]=find(parent[node],parent);
    }
    void Union(int node1,int node2,vector<int>&rank,vector<int>&parent){
        if(rank[node1]<rank[node2]){
            parent[node1]=node2;
        }
        else if(rank[node1]>rank[node2]){
            parent[node2]=node1;
        }
        else{
            parent[node2]=node1;
            rank[node1]++;
        }
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<int>parent(n,-1);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++)
        parent[i]=i;
        for(auto &edge:edges){
            adj[edge[0]-1].push_back(edge[1]-1);
            adj[edge[1]-1].push_back(edge[0]-1);
            int u=edge[0]-1;int v=edge[1]-1;
            u=find(u,parent);v=find(v,parent);
            if(u!=v){
                Union(u,v,rank,parent);
            }
        }
        int ans=0;
        unordered_map<int,int>groupAns;
        for(int i=0;i<n;i++){
            int curr=bfs(i,adj);
            if(curr==INT_MIN)
            return -1;
            int par=find(i,parent);
            groupAns[par]=max(groupAns[par],curr);
        }
        for(auto &each:groupAns)
        ans+=each.second;
        return ans;
    }
};