class Solution {
public:
    // void dfs(int s,int n,unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adjList){
    //     visited[s]=1;
    //     for(auto &nbr:adjList[s]){
    //         if(!visited[nbr])
    //         dfs(nbr,n,visited,adjList);
    //     }
    // }
    //int makeConnected(int n, vector<vector<int>>& connections) {
        // if(connections.size()<n-1)
        // return -1;
        // unordered_map<int,list<int>>adjList;
        // for(auto &edge:connections){
        //     adjList[edge[0]].push_back(edge[1]);
        //     adjList[edge[1]].push_back(edge[0]);
        // }
        // unordered_map<int,bool>visited;
        // int count=0;
        // for(int i=0;i<n;i++){
        //     if(!visited[i]){
        //         dfs(i,n,visited,adjList);
        //         count++;
        //     }
        // }
        // return count-1;
    //}





    //method 2
    int findParent(int u,vector<int>&parent){
       if(u==parent[u]) return u;
       return parent[u]=findParent(parent[u],parent);
    }
    void unionSet(int u,int v,vector<int>&parent,vector<int>&rank){
        u=findParent(u,parent);
        v=findParent(v,parent);
        if(rank[u]<rank[v]){
            parent[u]=v;
            rank[v]++;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>parent(n);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++)
        parent[i]=i;
        int extraedges=0;
        for(auto &edge:connections){
            int u=edge[0];
            int v=edge[1];
            if(findParent(u,parent)!=findParent(v,parent)){
                 unionSet(u,v,parent,rank);
            }
            else{
                extraedges++;
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
          if(parent[i]==i)
          count++;
        }
        int ans=count-1;
        return (extraedges>=ans)?ans:-1;
    }
};