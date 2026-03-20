class Solution {
public:
    void dfs(int node,vector<int>&edges,vector<int>&visited,int noOfNodes,int &ans){ 
        visited[node]=noOfNodes;
        if(edges[node]!=-1&&!visited[edges[node]])
        dfs(edges[node],edges,visited,noOfNodes+1,ans);
        else if(edges[node]!=-1&&visited[edges[node]]!=1)
        ans=max(ans,noOfNodes-visited[edges[node]]+1);
        visited[node]=1;
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int>visited(n,0);
        int ans=-1;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,edges,visited,2,ans);
            }
        }
        return ans;
    }
};