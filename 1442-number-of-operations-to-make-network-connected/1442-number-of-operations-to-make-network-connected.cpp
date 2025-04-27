class Solution {
public:
    void dfs(int s,int n,unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adjList){
        visited[s]=1;
        for(auto &nbr:adjList[s]){
            if(!visited[nbr])
            dfs(nbr,n,visited,adjList);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
        return -1;
        unordered_map<int,list<int>>adjList;
        for(auto &edge:connections){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        unordered_map<int,bool>visited;
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,n,visited,adjList);
                count++;
            }
        }
        return count-1;
    }
};