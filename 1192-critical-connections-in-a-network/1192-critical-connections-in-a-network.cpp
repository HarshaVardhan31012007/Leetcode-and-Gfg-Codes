class Solution {
public:
    void dfs(int src,vector<vector<int>>&adjList,vector<int>&visited,vector<int>&low,vector<vector<int>>&ans,int &t,vector<int>&in,int p){
        visited[src]=1;
        low[src]=t++;
        in[src]=low[src];
        for(auto &adj:adjList[src]){
            if(!visited[adj]){
                dfs(adj,adjList,visited,low,ans,t,in,src);
                low[src]=min(low[src],low[adj]);
                if(low[adj]>in[src]){
                    vector<int>temp;
                    temp.push_back(src);temp.push_back(adj);
                    ans.push_back(temp);
                }
            }
            else if(adj!=p){
                low[src]=min(low[src],in[adj]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adjList(n);
        for(auto &edge:connections){
           adjList[edge[0]].push_back(edge[1]);
           adjList[edge[1]].push_back(edge[0]);
        }
        vector<vector<int>>ans;
        vector<int>visited(n,0);
        vector<int>low(n,INT_MAX);
        vector<int>in(n,INT_MAX);
        int t=1;
        for(int i=0;i<n;i++){
            if(!visited[i])
            dfs(i,adjList,visited,low,ans,t,in,-1);
        }
        return ans;
    }
};