class Solution {
  public:
    void topoSort(int node,unordered_map<int,list<int>>&adjList,stack<int>&st,vector<int>&visited){
        visited[node]=1;
        for(auto &adj:adjList[node]){
            if(!visited[adj])
            topoSort(adj,adjList,st,visited);
        }
        st.push(node);
    }
    void dfs(int node,unordered_map<int,list<int>>&adjList,vector<int>&visited){
        visited[node]=1;
        for(auto &adj:adjList[node]){
            if(!visited[adj])
            dfs(adj,adjList,visited);
        }
    }
    int kosaraju(int V, vector<vector<int>> &edges) {
        unordered_map<int,list<int>>adjList;
        for(auto &each:edges){
            int u=each[0];
            int v=each[1];
            adjList[u].push_back(v);
        }
        stack<int>st;
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i])
            topoSort(i,adjList,st,visited);
        }
        unordered_map<int,list<int>>adjList1;
        for(auto &each:edges){
            int u=each[0];
            int v=each[1];
            adjList1[v].push_back(u);
        }
        vector<int>visited1(V,0);
        int count=0;
        while(!st.empty()){
            int each=st.top();
            st.pop();
            if(!visited1[each]){
                dfs(each,adjList1,visited1);
                count++;
            }
        }
        return count;
    }
};