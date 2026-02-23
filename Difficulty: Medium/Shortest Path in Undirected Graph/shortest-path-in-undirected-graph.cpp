class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        unordered_map<int,list<int>>adjList;
        for(auto &each:edges){
            int u=each[0];
            int v=each[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<int>spFromEach(V,INT_MAX);
        vector<int>visited(V,0);
        queue<int>q;
        q.push(src);
        visited[src]=1;
        spFromEach[src]=0;
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            for(auto &adj:adjList[front]){
                if(!visited[adj]){
                    spFromEach[adj]=1+spFromEach[front];
                    q.push(adj);
                    visited[adj]=1;
                }
            }
        }
        for(auto &each:spFromEach)
        each=((each==INT_MAX)?-1:each);
        return spFromEach;
    }
};
