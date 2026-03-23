class Solution {
  public:
    void dfs(int src,vector<int>adjList[],vector<int>&visited,vector<int>&low,set<int>&ans,int &t,vector<int>&in,int p,int &child){
        visited[src]=1;
        low[src]=t++;
        in[src]=low[src];
        for(auto &adj:adjList[src]){
            if(!visited[adj]){
                dfs(adj,adjList,visited,low,ans,t,in,src,child);
                low[src]=min(low[src],low[adj]);
                if(low[adj]>=in[src]&&p!=-1){
                    ans.insert(src);
                }
                if(p==-1){
                    child++;
                }
            }
            else if(adj!=p){
                low[src]=min(low[src],in[adj]);
            }
        }
    }
    vector<int> articulationPoints(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto &each:edges){
            adj[each[0]].push_back(each[1]);
            adj[each[1]].push_back(each[0]);
        }
        set<int>ans;
        vector<int>visited(n,0);
        vector<int>low(n,INT_MAX);
        vector<int>in(n,INT_MAX);
        int t=1;
        for(int i=0;i<n;i++){
            int child=0;
            if(!visited[i]){
                dfs(i,adj,visited,low,ans,t,in,-1,child);
                if(child>1){
                    ans.insert(i);
                }
            }
        }
        vector<int>fans;
        for(auto &each:ans){
            fans.push_back(each);
        }
        if(fans.empty()) fans.push_back(-1);
        return fans;
    }
};