class Solution {
public:
    // int find(int node,vector<int>&parent){
    //     if(parent[node]==node) return node;
    //     return find(parent[node],parent);
    // }
    // void unionHelp(int a,int b,vector<int>&parent,vector<int>&rank){
    //       if(rank[a]<rank[b]){
    //         parent[b]=a;
    //       }
    //       else{
    //         parent[a]=b;
    //       }
    // }
    // vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
    //     vector<int>parent(c,0);
    //     vector<int>rank(c,0);
    //     vector<bool>online(c,1);
    //     for(int i=0;i<c;i++){
    //         parent[i]=i;
    //         rank[i]=i;
    //     }
    //     for(auto &connection:connections){
    //           int u=connection[0]-1;
    //           int v=connection[1]-1;
    //           unionHelp(u,v,parent,rank);
    //     }
    //     return {};
    // }





    void dfs(int node,unordered_map<int,list<int>>&adjList,unordered_map<int,bool>&visited,unordered_map<int,set<int>>&mpp,int &id,vector<int>&nodeId){
        visited[node]=1;
        nodeId[node]=id;
        mpp[id].insert(node);
        for(auto &adj:adjList[node]){
            if(!visited[adj]){
                dfs(adj,adjList,visited,mpp,id,nodeId);
            }
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        unordered_map<int,list<int>>adjList;
        for(auto &connection:connections){
            adjList[connection[0]].push_back(connection[1]);
            adjList[connection[1]].push_back(connection[0]);
        }
        unordered_map<int,bool>visited;
        unordered_map<int,set<int>>mpp;
        vector<int>nodeId(c+1,0);
        for(int node=1;node<=c;node++){
            if(!visited[node])
            dfs(node,adjList,visited,mpp,node,nodeId);
        }
        vector<int>ans;
        for(auto &query:queries){
            int id=nodeId[query[1]];
            if(query[0]==1){
                 if(mpp[id].count(query[1])){
                    ans.push_back(query[1]);
                 }
                 else if(!mpp[id].empty())
                 ans.push_back(*(mpp[id].begin()));
                 else
                 ans.push_back(-1);
            }
            else{
               mpp[id].erase(query[1]);
            }
        }
        return ans;
    }
};