class Solution {
public:
    bool dfs(int src,vector<vector<int>>&graph,vector<int>&visited){
        visited[src]=2;
        for(auto &adj:graph[src]){
            if(!visited[adj]){
                bool ans=dfs(adj,graph,visited);
                if(ans) return true;
            }
            else if(visited[adj]==2) return true;
        }
        visited[src]=1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int no_of_nodes=graph.size();
        vector<int>visited(no_of_nodes,0);
        for(int i=0;i<no_of_nodes;i++){
            if(!visited[i]){
                dfs(i,graph,visited);
            }
        }
        vector<int>safeStates;
        for(int i=0;i<no_of_nodes;i++){
            if(visited[i]==1)
            safeStates.push_back(i);
        }
        return safeStates;
    }
};