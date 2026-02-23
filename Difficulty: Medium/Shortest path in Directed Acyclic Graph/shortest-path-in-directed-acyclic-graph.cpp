// User function Template for C++
class Solution {
  public:
    void topoSort(int src,vector<int>&visited,unordered_map<int,list<pair<int,int>>>&adjList,stack<int>&st){
        visited[src]=1;
        for(auto &adj:adjList[src]){
            int v=adj.first;
            if(!visited[v])
            topoSort(v,visited,adjList,st);
        }
        st.push(src);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        unordered_map<int,list<pair<int,int>>>adjList;
        for(auto &each:edges){
            int u=each[0];
            int v=each[1];
            int w=each[2];
            adjList[u].push_back({v,w});
        }
        vector<int>distance(V,INT_MAX);
        distance[0]=0;
        stack<int>st;
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
           if(!visited[i])
           topoSort(i,visited,adjList,st);
        }
        while(!st.empty()){
            auto top=st.top();
            st.pop();
            for(auto &adj:adjList[top]){
                int v=adj.first;int w=adj.second;
                if(distance[top]!=INT_MAX)
                distance[v]=min(distance[v],w+distance[top]);
            }
        }
        for(auto &each:distance)
        each=(each==INT_MAX?-1:each);
        return distance;
    }
};



